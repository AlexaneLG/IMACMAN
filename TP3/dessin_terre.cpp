#define GLEW_STATIC
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <vector>
#include <exception> 
#include <unistd.h>
#include <string>
#include <glimac/TrackballCamera.hpp>
// NANIIIII
using namespace glimac;

int main(int argc, char** argv) {
    /*if (argc < 3) {
        std::cerr << "Saisir le vertex shader puis le fragment shader." << std::endl;
    }
    std::string file1 = argv[1];
    std::string file2 = argv[2];*/
    std::string file1 = "3D.vs.glsl";
    std::string file2 = "tex3D.fs.glsl";

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

    std::unique_ptr<Image> texEarth = loadImage("D:/CLionProjects/TPS/asset/textures/EarthMap.jpg");
    if (texEarth == nullptr) {
       std::cout << "Le chargement de l'image terre à échoué." << std::endl;
    }

    std::unique_ptr<Image> texMoon = loadImage("D:/CLionProjects/TPS/asset/textures/MoonMap.jpg");
    if (texMoon == nullptr) {
       std::cout << "Le chargement de l'image lune à échoué." << std::endl;
    }

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
    TrackballCamera trackCamera;

    GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");

    GLuint earthTexture;
    glGenTextures(1, &earthTexture);
    glBindTexture(GL_TEXTURE_2D, earthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texEarth->getWidth(), texEarth->getHeight(), 0, GL_RGBA, GL_FLOAT, texEarth->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint moonTexture;
    glGenTextures(1, &moonTexture);
    glBindTexture(GL_TEXTURE_2D, moonTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texMoon->getWidth(), texMoon->getHeight(), 0, GL_RGBA, GL_FLOAT, texMoon->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

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

    std::vector<glm::vec3> axes;
    for(int i = 0; i < 32; i++){
        axes.push_back(glm::sphericalRand(1.f));
    }
   
    // Application loop:
    bool done = false; glm::ivec2 mousePos;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            if (windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
                mousePos = windowManager.getMousePosition();
                std::cout << mousePos << std::endl;
            }
        }

        /*********************************
         * RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = glm::rotate(MVMatrix, 0.001f, glm::vec3(0,1,0));

        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrix,  1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix,  1, GL_FALSE, glm::value_ptr(NormalMatrix));

        glBindVertexArray(vao);

        glBindTexture(GL_TEXTURE_2D, earthTexture);
        glUniform1i(uTexture, 0);

        glDrawArrays(GL_TRIANGLES, 0, n);
        glBindTexture(GL_TEXTURE_2D, moonTexture);

        for (int i = 0; i < axes.size(); i++) {
            glm::mat4 MVMatrix2;

            MVMatrix2 = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
            MVMatrix2 = glm::rotate(MVMatrix2, windowManager.getTime() + i, axes[i]);
            MVMatrix2 =glm::translate(MVMatrix2, glm::vec3(-2,0,0));
            MVMatrix2 = glm::scale(MVMatrix2, glm::vec3(0.2,0.2,0.2));

            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix2));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix2));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            glDrawArrays(GL_TRIANGLES, 0, n);
        }
        glBindTexture(GL_TEXTURE_2D, 0); //debind texture
        glBindVertexArray(0);

        windowManager.swapBuffers();
    }
    glDeleteTextures(1, &earthTexture);
    glDeleteTextures(1, &moonTexture);
    return EXIT_SUCCESS;
}
