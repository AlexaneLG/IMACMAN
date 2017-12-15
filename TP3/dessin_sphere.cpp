#define GLEW_STATIC
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <vector>
#include <exception> 
#include <unistd.h>
#include <string>

using namespace glimac;

int main(int argc, char** argv) {
    /*if (argc < 3) {
        std::cerr << "Saisir le vertex shader puis le fragment shader." << std::endl;
    }
    std::string file1 = argv[1];
    std::string file2 = argv[2];*/
    std::string file1 = "3D.vs.glsl";
    std::string file2 = "normals.fs.glsl";

    // Initialize SDL and open a window
    SDLWindowManager windowManager(600, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
   
    FilePath applicationPath;
    Program program;
    try
    {
        applicationPath = FilePath(argv[0]);
        program = loadProgram(applicationPath.dirPath() + "shaders/" + file1, applicationPath.dirPath() + "shaders/" + file2); //ERREUR ICI  
        program.use();
    } 
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    /*********************************
     * INITIALIZATION CODE
     *********************************/
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    glEnable(GL_DEPTH_TEST);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), float(600)/600, 0.1f, 100.f);
    glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0, 0, -5));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glm::mat4 MVPMatrix = ProjMatrix * MVMatrix;

    Sphere sphere(1, 32, 16);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    int n = sphere.getVertexCount();
    const ShapeVertex *sommets = sphere.getDataPointer();
    glBufferData(GL_ARRAY_BUFFER, n*sizeof(ShapeVertex), sommets, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORDS = 2;

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, position)));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, normal)));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


   
    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * RENDERING CODE
         *********************************/
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(MVPMatrix));
         glUniformMatrix4fv(uMVMatrix,  1, GL_FALSE, glm::value_ptr(MVMatrix));
         glUniformMatrix4fv(uNormalMatrix,  1, GL_FALSE, glm::value_ptr(NormalMatrix));

         glBindVertexArray(vao);
         glDrawArrays(GL_TRIANGLES, 0, n);
         glBindVertexArray(0);

        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
