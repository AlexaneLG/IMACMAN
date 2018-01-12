//
// Created by no on 07/01/18.
//

#include "glimac/pacmanShape.h"
#include <glimac/Sphere.hpp>
#include "glimac/Image.hpp"

PacmanShape::PacmanShape(glimac::Sphere sphere): m_sphere(sphere){

}
void PacmanShape::load(){
    //load textures
    /*FilePath texPath("/home/no/synth_img/GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> earthTex = loadImage(texPath);
    if(earthTex == NULL){
        std::cout << "Problem loading texture!" << std::endl;
    }
*/
}

glimac::Sphere PacmanShape::sphere(){
    return m_sphere;
}