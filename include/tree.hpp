// Include once.
#pragma once

// Dependencies.
#include "gameobject.hpp"

// A class representing a tree.
class Tree:public GameObject{
    private:
         
    public:
        // Override the base function from the GameObject file,printing the T for tree object.
        void DrawGameObject();

        // Override the base function from the GameObject file,returning the enum type,which in this case is tree.
        GAME_OBJECT_TYPE GetGameObjectType();

};