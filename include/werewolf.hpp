// Include once.
#pragma once

// Dependencies.
#include "entity.hpp"

// A class representing a werewolf.
class WereWolf : public Entity {
    private:
        // Werewolf's health.
        int hp;
        
        // The maximum hp of the werewolf.
        int max_hp;
        
        // The number of times this werewolf can heal a teamate.
        int nums_of_heals;

        // The power of the werewolf. 
        int power;

        // The defence of the werewolf.
        int defence;
    public:
        // Creates a werewolf object.
        WereWolf();
        
        // Returns the hp of the Werewolf.
        int GetHP();

        // Returns the number of health kits.
        int GetHealthKitCount();

        // Updates the number of health kits.
        void UpdateHealthKitCount(int health_kit_count);

        // Returns the defence of the werewolf.
        int GetDefence();

        // Returns the power of the werewolf.
        int GetPower();

        // Updates the power of the werewolf.
        int UpdatePower();

        // Updates the hp of the object.
        void UpdateHP(int hp);

        // Gets the maximum hp of the object.
        int GetMaximumHP();

        // Override the base function from the GameObject file,printing the W for werewolf object.
        void DrawGameObject();

        // Override the base function from the GameObject file,returning the enum type,which in this case is werewolf.
        GAME_OBJECT_TYPE GetGameObjectType();

        // Updates the entity object.
        bool UpdateEntity(std::vector<GameObject*> game_objects, Size size);
};