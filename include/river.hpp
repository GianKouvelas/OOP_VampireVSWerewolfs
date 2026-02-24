// Include once.
#pragma once 

// Dependencies.
#include "gameobject.hpp"

// A class representing a river.
class River:public GameObject {
    public:
        // Override the base function from the GameObject file,printing the R for river object.
        void DrawGameObject();

        // Override the base function from the GameObject file,returning the enum type,which in this case is river.
        GAME_OBJECT_TYPE GetGameObjectType();
};