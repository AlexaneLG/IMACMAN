#pragma once

#include "Sphere.hpp"
#include "Image.hpp"


    class PacmanShape {
    private:
        glimac::Sphere m_sphere;
        //glimac::Image texture;
        //pacmanProgram program;

    public:
        PacmanShape(glimac::Sphere sphere = glimac::Sphere(1,  32,  16));

        void load();

        void draw();

        glimac::Sphere sphere();
    };