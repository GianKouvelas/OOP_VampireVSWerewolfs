// Dependencies.
#include <iostream>
#include "../include/river.hpp"
#include "../include/gameobject.hpp"

///////////////////////////////////////////
//
// River's method implementations.
//
///////////////////////////////////////////

// Override the base function from the GameObject file,printing the R for river object.
void River::DrawGameObject() {
    std::cout << "\033[33mR\033[0m";
}

// Override the base function from the GameObject file,returning the enum type,which in this case is river.
GAME_OBJECT_TYPE River::GetGameObjectType() {
    return RIVER;
}