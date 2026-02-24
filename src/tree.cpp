// Dependencies.
#include <iostream>
#include "../include/tree.hpp"
#include "../include/gameobject.hpp"

///////////////////////////////////////////
//
// Tree's method implementations.
//
///////////////////////////////////////////

// Override the base function from the GameObject file,printing the T for tree object.
void Tree::DrawGameObject() {
    std::cout << "\033[33mT\033[0m";
}

// Override the base function from the GameObject file,returning the enum type,which in this case is tree.
GAME_OBJECT_TYPE Tree::GetGameObjectType() {
    return TREE;
}