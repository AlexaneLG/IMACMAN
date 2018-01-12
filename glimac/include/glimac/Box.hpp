//
// Created by no on 09/01/18.
//
#pragma once
#include <vector>
#include "common.hpp"

class Box {
public:

    Box(){
        m_length = 1;
        m_width = 1;
        m_height = 1;
        m_center = glm::vec3(0, 0, 0);
        m_nVertexCount = 12;
        build(m_length, m_width, m_height);
    }

    Box(GLfloat length, GLfloat width, GLfloat height): m_nVertexCount(0) {
        build(length, width, height); // Construction (voir le .cpp)
    }

    // Alloue et construit les données (implantation dans le .cpp)
    void build(GLfloat length, GLfloat width, GLfloat height);

    // Renvoit le pointeur vers les données
    const glimac::ShapeVertex* getDataPointer() const {
        return &m_Vertices[0];
    }

    // Renvoit le nombre de vertex
    GLsizei getVertexCount() const {
        return m_nVertexCount;
    }

    std::vector<uint32_t> indices() {
        std::vector<uint32_t> indices;
        for(int i = 0; i < m_indices.size(); i++){
            std::vector<uint32_t> temp_indices = m_indices[i];
            indices.push_back(temp_indices[0]);
            indices.push_back(temp_indices[1]);
            indices.push_back(temp_indices[2]);
        }

        return indices;
    }

private:
    std::vector<glimac::ShapeVertex> m_Vertices;
    std::vector<std::vector<uint32_t>> m_indices;
    GLfloat m_length;
    GLfloat m_width;
    GLfloat m_height;
    glm::vec3 m_center;
    GLsizei m_nVertexCount; // Nombre de sommets
};
