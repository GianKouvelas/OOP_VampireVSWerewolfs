// Include once.
#pragma once

// Dependencies.
#include "size.hpp"
#include <vector>
#include "gameobject.hpp"
#include "avatar.hpp"
#include "werewolf.hpp"
#include "vampire.hpp"
#include "ground.hpp"
#include "tree.hpp"
#include "river.hpp"
#include "clock.hpp"

// A class representing the map of the game.
class Map {
    private:
        // A vector containing all the game objects present in the map.
        std::vector<GameObject*> game_objects;

        // The size of the map.
        Size map_size;

        // A direct pointer to the avatar.
        Avatar* avatar_ptr;

        // Creates objects for the map.
        void FillMap(Size size);

        // Creates and places the avatar to the map.
        void CreateAndPlaceAvatar(int x, int y);

        // Creates and places the werewolves to the map.
        void CreateAndPlaceWereWolves(Size size);

        // Creates and places the vampires to the map.
        void CreateAndPlaceVampires(Size size);

        // Creates and places the other objects to the map.
        void CreateAndPlaceOthers(Size size);

        // Creates and places a ground object to the map.
        void CreateAndPlaceGround(int x,int y);

        // Creates and places a tree object to the map.
        void CreateAndPlaceTree(int x, int y);

        // Creates and places a river object to the map.
        void CreateAndPlaceRiver(int x, int y);

        // Creates and places a potion on the ground.
        void CreateAndPlacePotion(int x, int y);
    public:
        // Creates a map.
        Map();

        // Creates a map with a predefined size.
        Map(Size size);

        // Returns a pointer to the avatar.
        Avatar* GetAvatar();

        // Gets the number of vampires.
        int GetVampireCount();

        // Gets the number of werewolves.
        int GetWereWolfCount();

        // Returns the object present in the map.
        std::vector<GameObject*> GetGameObjects();

        // Deletes a game object from the map.
        void DeleteGameObject(GameObject* game_object);

        // Updates the game's map.
        void UpdateMap(Clock& clock, bool& is_paused);

        // Draws the map to the screen.
        void DrawMap(Clock clock);
        
        // Destroys a map.
        ~Map();
};
