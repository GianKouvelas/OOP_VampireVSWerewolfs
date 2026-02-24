// Include once.
#pragma once

// Dependencies.
#include "gameobject.hpp"

// A class representing a potion bottle.
class Potion:public GameObject {
    private:
        // This is false if the potion has been used.
        bool used;
    public:
        // Creates a potion object.
        Potion();

        // Updates the potion coordinates.
        void UpdatePotion(Point2D cords);

        // Returns true if the potion has been used.
        bool IsUsed();

        // Uses the potion.
        void UsePotion();
        
        // Override the base function from the GameObject file,printing the P for the potion object.
        void DrawGameObject();

        // Override the base function from the GameObject file,returning the enum type,which in this case the potion.
        GAME_OBJECT_TYPE GetGameObjectType();

};

