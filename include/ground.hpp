// Include once.
#pragma once

// Dependencies.
#include "gameobject.hpp"

// A class representing a ground object.
class Ground:public GameObject {        
    public:
        // Creates a ground object.
        Ground();

        // Override the base function from the GameObject file,printing a blank space for ground object.
        void DrawGameObject();

        // Override the base function from the GameObject file,returning the enum type,which in this case is ground.
        GAME_OBJECT_TYPE GetGameObjectType(); 
};