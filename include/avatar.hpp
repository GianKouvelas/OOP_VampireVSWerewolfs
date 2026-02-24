// Include once.
#pragma once

// Dependencies.
#include "entity.hpp"
#include "potion.hpp"
#include "input.hpp"
#include "clock.hpp"

// An enum tracking the possible actions of the avatar.
namespace legal_actions {
    typedef enum {UP, DOWN, LEFT, RIGHT, PAUSE, HEAL} LegalActions;
};

class Avatar : public Entity {
        private:
            // The number of potions.
            int potions;

            // A boolean tracking avatar's team.
            bool is_werewolf;
        public:
            // Creates an Avatar object.
            Avatar();

            // Updates the avatar's team.
            void UpdateTeam(bool is_werewolf);
            
            // Updates the number of potions.
            void UpdatePotionCount(int potion_count);

            // Returns the number of potions.
            int GetPotionCount();

            // Return the team of the avatar (true=Werewolf & false=Vampire).
            bool IsWereWolf();  

            // Override the base function from the GameObject file,printing the A for avatar object.
            void DrawGameObject();

            // Override the base function from the GameObject file,returning the enum type,which in this case is avatar.
            GAME_OBJECT_TYPE GetGameObjectType();

            // Only used for debugging purposes.
            void DebugAvatar();

            // Updates the legal actions of the avatar. 
            void GetLegalActions(std::vector<GameObject*> game_objects, std::vector<legal_actions::LegalActions>& actions);

            // Updates the avatar.
            bool UpdateEntity(std::vector<GameObject*> game_objects, Size size, bool is_gamestate_paused, Clock clock);
};
