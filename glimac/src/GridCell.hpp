//
// Created by no on 11/01/18.
//

#pragma once
#include <cmath>
#include <vector>
#include "glimac/common.hpp"
#include "GameElement.hpp"

class GridCell {
private:
    glm::vec3 m_dimensions;
    glm::vec3 m_coords;
    std::vector<bool> m_directions;
    GameElement m_element;

public:
    GridCell();
    void interact(Pacman * pacman);
};