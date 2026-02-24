// Include once.
#pragma once

// Dependencies.
#include "entity.hpp"

// A class representing a vampire.
class Vampire:public Entity {
        private: 
                // The health of the entity.
                int hp;

                // The number of times this vampire can heal a teamate.
                int nums_of_heals;

                // The power of the vampire.
                int power;

                // The defence of the vampire.
                int defence;

                // The vampire's maximum hp.
                int max_hp;
            public:
                // Creates a vampire object.
                Vampire();
                
                // Returns the number of health kits.
                int GetHealthKitCount();

                // Gets the maximum hp of the object.
                int GetMaximumHP();

                // Updates the number of health kits.
                void UpdateHealthKitCount(int health_kit_count);

                // Returns the hp of the Vampire.
                int GetHP();

                // Returns the power of the werewolf.
                int GetPower();
                
                // Returns the defence of the werewolf.
                int GetDefence();
                
                // Updates the hp of the object.
                void UpdateHP(int hp);

                // Override the base function from the GameObject file,printing the V for vampire object.
                void DrawGameObject();

                // Override the base function from the GameObject file,returning the enum type,which in this case is vampire.
                GAME_OBJECT_TYPE GetGameObjectType();

                // Updates the vampire.
                bool UpdateEntity(std::vector<GameObject*> game_objects, Size size);
};              