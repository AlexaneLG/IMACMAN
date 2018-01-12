//
// Created by no on 09/01/18.
//
#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/Box.hpp"

void Box::build(GLfloat length, GLfloat width, GLfloat height){
    std::vector<glimac::ShapeVertex> data;

    // Construire l'ensemble des vertex
    //FACE 1 BAS
        /*First Vertex (bottom face, top left corner*/
    glimac::ShapeVertex vertex;
        vertex.texCoords.x = 0;
        vertex.texCoords.y = 0;

        vertex.normal.x = 0;
        vertex.normal.y = 1;
        vertex.normal.z = 0;

        vertex.position = glm::vec3(-0.5, -0.5, -0.5);

        data.push_back(vertex);

        /*2d Vertex (bottom face, top right corner*/
    vertex.texCoords.x = 1;
    vertex.texCoords.y = 1;

    vertex.normal.x = 0;
    vertex.normal.y = 1;
    vertex.normal.z = 0;

    vertex.position = glm::vec3(0.5, -0.5, -0.5);

    data.push_back(vertex);

    /*3d Vertex (bottom face, bottom right corner*/
    vertex.texCoords.x = 0;
    vertex.texCoords.y = 1;

    vertex.normal.x = 0;
    vertex.normal.y = 1;
    vertex.normal.z = 0;

    vertex.position = glm::vec3(0.5, -0.5, 0.5);

    data.push_back(vertex);

    /*4th Vertex (bottom face, bottom left corner*/
    vertex.texCoords.x = 1;
    vertex.texCoords.y = 0;

    vertex.normal.x = 0;
    vertex.normal.y = 1;
    vertex.normal.z = 0;

    vertex.position = glm::vec3(-0.5, -0.5, 0.5);

    data.push_back(vertex);

    //FACE 3 TOP
    int size = data.size();
    for(int i = size-4; i < size; i++){
        glm::mat4 translated =  glm::translate(glm::mat4(), glm::vec3(0,1,0));
        glm::vec4 transform = translated*glm::vec4(data[i].position,1);
        glm::vec4 normal_transform = translated * glm::vec4(data[i].normal,1);
        vertex.position = glm::vec3(transform);
        vertex.normal = glm::vec3(normal_transform);
        data.push_back(vertex);
    }

    //FACE 3 LEFT
    for(int i = 0; i < 4; i++){
        glm::mat4 rotated = glm::rotate(glm::mat4(), glm::radians(90.0f), glm::vec3(0,0,1));
        glm::vec4 transform = rotated*glm::vec4(data[i].position,1);
        vertex.position = glm::vec3(transform);
        data.push_back(vertex);
    }

    //FACE 4 RIGHT
    size = data.size();
    for(int i = size -4; i < size; i++){
        glm::mat4 translated =  glm::translate(glm::mat4(), glm::vec3(-1,0,0));
        glm::vec4 transform = translated*glm::vec4(data[i].position,1);
        vertex.position = glm::vec3(transform);
        data.push_back(vertex);
    }

    //FACE 5 BACK
    for(int i = 0; i < 4; i++){
        glm::mat4 rotated = glm::rotate(glm::mat4(), glm::radians(90.0f), glm::vec3(1,0,0));
        glm::vec4 transform = rotated*glm::vec4(data[i].position,1);
        vertex.position = glm::vec3(transform);
        data.push_back(vertex);
    }

    //FACE 6 FRONT
    size = data.size();
    for(int i = size -4; i < size; i++){
        glm::mat4 translated =  glm::translate(glm::mat4(), glm::vec3(0,0,1));
        glm::vec4 transform = translated*glm::vec4(data[i].position,1);
        vertex.position = glm::vec3(transform);
        data.push_back(vertex);
    }
    m_Vertices = data;

    m_nVertexCount = 24;

    std::vector<std::vector<uint32_t>> indices;
    for(int j = 0, i=0; j < 6; j++){
        indices.push_back({i,i+1,i+2});
        indices.push_back({i,i+2,i+3});
        i +=4;
    }
/*
    //*FACE 1 BAS*
    indices.push_back({0,2,3});
    indices.push_back({0,1,2});
    //*FACE 2 HAUT*
    indices.push_back({4,5,6});
    indices.push_back({4,6,7});
    //FACE 3 LEFT*
    indices.push_back({8,9,10});
    indices.push_back({8,10,11});


    //FACE 4 RIGHT
    indices.push_back({12,13,14});
    indices.push_back({12,13,15});

    //FACE 5 RIGHT
    indices.push_back({16,17,18});
    indices.push_back({16,18,19});

    //FACE 6 RIGHT
    indices.push_back({20,21,22});
    indices.push_back({20,22,23});*/

    m_indices = indices;

    // Attention ! dans cette implantation on duplique beaucoup de sommets. Une meilleur stratégie est de passer
    // par un Index Buffer Object, que nous verrons dans les prochains TDs
}