//
// Created by no on 07/01/18.
//
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
//#include <glimac/TrackballCamera.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <SDL/SDL.h>
#include "glimac/pacmanShape.h"

using namespace glimac;

struct pacmanProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uEarthTexture;
    GLint uCloudTexture;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightDir_vs;
    GLint uLightIntensity;

    pacmanProgram(const FilePath& applicationPath):
            m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                  applicationPath.dirPath() + "shaders/directionallight.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
        uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
        uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
        uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
        uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
        uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
    }
};

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //load textures
    /*FilePath texPath("/home/no/synth_img/GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> earthTex = loadImage(texPath);
    if(earthTex == NULL){
        std::cout << "Problem loading texture!" << std::endl;
    }

    texPath = FilePath("/home/no/synth_img/GLImac-Template/assets/textures/MoonMap.jpg");
    std::unique_ptr<Image> moonTex = loadImage(texPath);
    if(moonTex == NULL){
        std::cout << "Problem loading texture!" << std::endl;
    }

    texPath = FilePath("/home/no/synth_img/GLImac-Template/assets/textures/CloudMap.jpg");
    std::unique_ptr<Image> cloudTex = loadImage(texPath);
    if(cloudTex == NULL){
        std::cout << "Problem loading texture!" << std::endl;
    }*/

    //load shaders

    FilePath applicationPath(argv[0]);
    pacmanProgram pacmanProgram(applicationPath);

    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    //Sphere sphere(1,  32,  16);
    PacmanShape pacshape(Sphere(1,  32,  16));

    //TEXTURES
    /*GLuint earthTexture;
    glGenTextures(1, &earthTexture);
    glBindTexture(GL_TEXTURE_2D, earthTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, earthTex->getWidth(), earthTex->getHeight(),0, GL_RGBA, GL_FLOAT, (const GLvoid*)earthTex->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);*/


    /*GLuint createVBO(Shape shape){

    //Create VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    //Bind VBO to target GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Fill in the VBO to create a sphere
    glBufferData(GL_ARRAY_BUFFER, shape.getVertexCount() * sizeof(ShapeVertex),
                 shape.getDataPointer(), GL_STATIC_DRAW); //send vertices data

    //Un-bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    return vbo;
}*/

    //Create VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    //Bind VBO to target GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Fill in the VBO to create a sphere
    glBufferData(GL_ARRAY_BUFFER, pacshape.sphere().getVertexCount()*sizeof(ShapeVertex), pacshape.sphere().getDataPointer(), GL_STATIC_DRAW); //send vertices data

    //Un-bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /**VAO**/
    //Create VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //Bind VAO
    glBindVertexArray(vao);

    //Enable vertices attributes : indices are found in the shader triangle.vs.gls
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORDS = 2;

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

    //bind VBO to target GL_ARRAY_BUFFER, to associate the correct VBO data to the VAO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Specify vertices attributes
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //un-bind VAO
    glBindVertexArray(0);

    //compute matrices
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)800/600 , 0.1f, 100.f); //ratio width/height

    std::vector<glm::vec3> axes;
    for(int i =0; i < 32; i++){
        axes.push_back(glm::sphericalRand(1.f));
    }

    std::vector<glm::vec3> coefs;
    for(int i =0; i < 3*32; i++){
        coefs.push_back(glm::sphericalRand(1.f));
    }

    FreeflyCamera ffly_camera;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        float move_front, move_left, rotateX, rotateY;
        move_front = move_left = rotateX = rotateY = 0;
        bool reset = false;
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            /*mouse events*/
            /*press the mouse's right button to rotate*/
            //move the mouse vertically to rotate vertically
            //move the mouse horizontally to rotate horizontally
            if(windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)){
                if(e.motion.xrel) rotateX = e.motion.xrel/glm::abs(e.motion.xrel);
                if(e.motion.yrel) rotateY = e.motion.yrel/glm::abs(e.motion.yrel);
            }

            //move the mouse vertically to move forward or backward
            if(windowManager.isMouseButtonPressed(SDL_BUTTON_MIDDLE)){
                if(e.type == SDL_MOUSEMOTION && e.motion.yrel != 0){
                    move_front = e.motion.yrel/glm::abs(e.motion.yrel);
                }
            }

            /*keyboard events*/
            //use the Z,Q,S,D to move
            // Z (forward), S(backward)
            //Q(Left), D (right)
            if(windowManager.isKeyPressed(SDLK_z)) move_front = 1;
            if(windowManager.isKeyPressed(SDLK_q)) move_left = 1;
            if(windowManager.isKeyPressed(SDLK_s)) move_front = -1;
            if(windowManager.isKeyPressed(SDLK_d)) move_left = -1;

            //use r to reset the camera to its original position
            if(windowManager.isKeyPressed(SDLK_r)) reset = true;

        }
        ffly_camera.rotateLeft(rotateX);
        ffly_camera.rotateUp(rotateY);
        ffly_camera.moveFront(move_front);
        ffly_camera.moveLeft(move_left);
        //reset the camera to default if needed
        if(reset){
            ffly_camera = FreeflyCamera();
            reset = false;
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Bind vao
        glBindVertexArray(vao);

        //Uniform Matrices

        glm::mat4 viewMatrix = ffly_camera.getViewMatrix();
        glm::mat4 modelMatrix = glm::translate(glm::mat4(), glm::vec3(0,0,-5));
        glm::mat4 globalMVMatrix = viewMatrix * modelMatrix;

        /*glm::mat4 globalNormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));
        glm::mat4 globalMVPMatrix = ProjMatrix * globalMVMatrix;*/

        //Lights
        glm::vec3 lightIntensity = glm::vec3(40,0.55,1);

        glm::vec4 lightDirCoef = glm::vec4(1,1,1,0);
        lightDirCoef = lightDirCoef * glm::rotate(glm::mat4(), windowManager.getTime(), glm::vec3(0,1,0));
        lightDirCoef = (lightDirCoef* viewMatrix);

        //EARTH

        //activate program
        pacmanProgram.m_Program.use();

        //send uniforms
        glUniform1i(pacmanProgram.uEarthTexture, 0);
        glUniform1i(pacmanProgram.uCloudTexture, 1);

        //lights
        glUniform3f(pacmanProgram.uLightIntensity,lightIntensity.x,lightIntensity.y,lightIntensity.z);
        glUniform3f(pacmanProgram.uLightDir_vs,lightDirCoef.x, lightDirCoef.y, lightDirCoef.z);

        //materials
        glUniform3f(pacmanProgram.uKd, 0.5,0.5,1);
        glUniform3f(pacmanProgram.uKs, 0.5,0.5,1);
        glUniform1f(pacmanProgram.uShininess,0.1);

        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, windowManager.getTime(), glm::vec3(0,1,0));

        glUniformMatrix4fv(pacmanProgram.uMVMatrix, 1, GL_FALSE,
                           glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(pacmanProgram.uMVPMatrix, 1, GL_FALSE,
                           glm::value_ptr(ProjMatrix * earthMVMatrix));
        glUniformMatrix4fv(pacmanProgram.uNormalMatrix, 1, GL_FALSE,
                           glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));

        //Bind textures
        /*glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, earthTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, cloudTexture);*/

        glDrawArrays(GL_TRIANGLES, 0, pacshape.sphere().getVertexCount());

        //Un-bind textures
        glBindVertexArray(0);
        /*glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);*/

        // Update the display
        windowManager.swapBuffers();
    }

    /*free resources*/
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    /*glDeleteTextures(1, &earthTexture);
    glDeleteTextures(1, &moonTexture);
    glDeleteTextures(1, &cloudTexture);*/

    return EXIT_SUCCESS;
}
