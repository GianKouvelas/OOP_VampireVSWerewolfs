// Dependencies.
#include <iostream>
#include "../include/ground.hpp"
#include "../include/gameobject.hpp"

///////////////////////////////////////////
//
// Ground's method implementations.
//
///////////////////////////////////////////

// Creates a ground object.
Ground::Ground() {

}

// Override the base function from the GameObject file,printing a blank space for ground object.
void Ground::DrawGameObject() {
    std::cout << " ";
}

// Override the base function from the GameObject file,returning the enum type,which in this case is ground.
GAME_OBJECT_TYPE Ground::GetGameObjectType() {
    return GROUND;
}