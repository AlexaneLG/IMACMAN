//
// Created by no on 10/01/18.
//

#pragma once
#include <vector>
#include "glimac/common.hpp"
#include "glimac/Box.hpp"

class GameGrid {
private:
    std::vector<int> m_elements;
    //std::vector<Case> m_case_grid;//draw the element corresponding to eachcase
    glm::vec3 starting_point;
    glm::mat4 translate_right_matrix;
    glm::mat4 translate_down_matrix;
    float m_width_factor; //depend de la largeur de la case
    float m_depth_factor;
    float m_height_factor; //depend de la longueur de la case
    int m_nbCols;
    int m_nbRows;

public:
    GameGrid(){
        m_width_factor = 1;
        m_depth_factor = 1;
        m_height_factor = 1;
        m_nbCols = 0;
        m_nbRows = 0;
    }
    /*glm::mat4 translateRightMatrix(){
        glm::mat4 translate = glm::translate(glm::vec3(width_factor, 0, 0)); //view ? ajuster le labyrinthe
        return translate;
    }*/
    std::vector<int> elements(){
        return m_elements;
    }

    int elements(int i,int j) const {
        return m_elements[m_nbCols * i + j];
    }

    int nbRows() const {
        return m_nbRows;
    }

    int nbCols() const {
        return m_nbCols;
    }

    void setElements(const std::vector<int> &elements){
        m_elements = elements;
    }

    void setNbCols(const int &nbCols){
        m_nbCols = nbCols;
    }

    void setNbRows(const int &nbRows){
        m_nbRows = nbRows;
    }
};
