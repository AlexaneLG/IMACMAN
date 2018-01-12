//
// Created by no on 11/01/18.
//

#pragma once
#include <vector>
#include "glimac/common.hpp"
#include "Pacman.hpp"

class GameElement {
private:

public:
    GameElement();
    void interact();
    virtual void interact(Pacman * pacman);
};