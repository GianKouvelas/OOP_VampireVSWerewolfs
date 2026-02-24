// Include once.
#pragma once

// Dependencies.
#include <iostream>
#include "point2d.hpp"
#include <vector>

// These types are used for identifying the game objects.
typedef enum {AVATAR, VAMPIRE, WEREWOLF, POTION, TREE, RIVER, GROUND, GAME_OBJECT} GAME_OBJECT_TYPE;

// A class representing a game object.
class GameObject {
    private:
        Point2D cords; // Coordinates for each entity (avatar,vampire etc.)
    public:
        // Creates a game object.
        GameObject();

        // Returns the x value of the game object.
        int GetX();

        // Returns the y value of the game object.
        int GetY();

        // Updates both the x and y value of the game object.
        void UpdateXY(int x, int y);

        // Updates the x value of the game object.
        void UpdateX(int x);

        // Updates the y value of the game object.
        void UpdateY(int y);

        // Returns true if two game object collide.
        bool DoGameObjectsCollide(GameObject game_object);
        
        // Returns the type of the game object.
        virtual GAME_OBJECT_TYPE GetGameObjectType();

        // Draws the game object.
        virtual void DrawGameObject();
};

