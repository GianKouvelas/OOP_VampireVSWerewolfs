// Dependencies.
#include <iostream>
#include "../include/avatar.hpp"
#include "unistd.h"
#include "../include/werewolf.hpp"
#include "../include/vampire.hpp"
#include <algorithm>

///////////////////////////////////////////
//
// The Avatar's method implementations.
//
///////////////////////////////////////////

// Creates an Avatar object.
Avatar::Avatar() {
    this->potions=1; //Adds the avatar potions
    this->is_werewolf=true; //Firstly the avatar is with the werewolf team
}

// Updates the avatar's team.
void Avatar::UpdateTeam(bool team) {
    this->is_werewolf=team;  
}

// Updates the number of potions.
void Avatar::UpdatePotionCount(int potion_count) {
    this->potions=potion_count;
}

// Returns the number of potions.
int Avatar::GetPotionCount() {
    return this->potions;
}

// Return the team of the avatar (true=Werewolf & false=Vampire).
bool Avatar::IsWereWolf() {
    return this->is_werewolf;
}

// Override the base function from the GameObject file,printing the A for avatar object.
void Avatar::DrawGameObject() {
    // Colors the avatar identifier based on his team.
    if (this->is_werewolf) {
        std::cout << "\033[36mA\033[0m"; 
    } else {
        std::cout << "\033[31mA\033[0m"; 
    }
}

// Override the base function from the GameObject file,returning the enum type,which in this case is avatar.
GAME_OBJECT_TYPE Avatar::GetGameObjectType() {
    return AVATAR;
}

// Only used for debugging purposes.
void Avatar::DebugAvatar() {
    // Prints a debugging message.
    std::cout<<"Avatar : (x = "<<this->GetX()<<", y = "<<this->GetY()<<")";
    std::cout<<" Potion Count = "<<this->potions<<" TeamWerewolf : "<<this->is_werewolf<<"\n";
}

// Updates the legal actions of the avatar. 
void Avatar::GetLegalActions(std::vector<GameObject*> game_objects, std::vector<legal_actions::LegalActions>& actions) {
    // These variables are used to find the lagal movements of the avatar.
    bool is_up, is_down, is_left, is_right = false;
    
    // Eliminates any non legal moves.
    for (auto game_object : game_objects) {
        // Checks if there is an object next to the avatar.
        if (this->DoGameObjectsCollide(*game_object)) {
            // Checks if there is a non ground/potion-object next to the avatar.
            if ((game_object->GetGameObjectType() != GROUND) && (game_object->GetGameObjectType() != POTION)) {
                // Checks if the object is infront of the avatar.
                if ((game_object->GetX() == this->GetX()) && (game_object->GetY() < this->GetY())) {
                    is_up = true;
                } else if ((game_object->GetX() == this->GetX()) && (game_object->GetY() > this->GetY())) {
                    is_down = true;
                } else if ((game_object->GetX() > this->GetX()) && (game_object->GetY() == this->GetY())) {
                    is_right = true;
                } else if ((game_object->GetX() < this->GetX()) && (game_object->GetY() == this->GetY())) {
                    is_left = true;
                }
            } else if (game_object->GetGameObjectType() == POTION) {
                // Increases the potion counter
                this->UpdatePotionCount(this->GetPotionCount()+1);

                // Downcasts the game object to potion.
                Potion* potion_ptr = dynamic_cast<Potion*>(game_object);

                // Sets the potion to inactive.
                potion_ptr->UsePotion();
            }
        }
    }

    // Updates the legal actions.
    if (!is_up) {actions.push_back(legal_actions::UP);}
    if (!is_down) {actions.push_back(legal_actions::DOWN);}
    if (!is_left) {actions.push_back(legal_actions::LEFT);}
    if (!is_right) {actions.push_back(legal_actions::RIGHT);}
    if (this->GetPotionCount() > 0) {actions.push_back(legal_actions::HEAL);}
}

// Updates the avatar.
bool Avatar::UpdateEntity(std::vector<GameObject*> game_objects, Size size, bool is_gamestate_paused, Clock clock) {
    // A vector holding the legal actions of the avatar.
    std::vector<legal_actions::LegalActions> possible_actions;

    // Gets the legal actions of the avatar.
    this->GetLegalActions(game_objects, possible_actions);

    // This is a useful boolean for the loop below.
    bool action_is_legal = false;

    // The loop runs until a legal action is given.
    do {
        // Gets the input of the player.
        PlayerInput player_input = Input::GetInput();

        // Ensures that the input was valid.
        while(player_input == INVALID) {
            // Prints a helpful message.
            std::cout<<"?? Error ?? : Invalid Input"<<"\n";

            player_input = Input::GetInput();
        }

        // Returns true if a pause action happened.
        if (player_input == PAUSE) {return true;}

        // Returns false if no pause action happened and the game is paused.
        if (is_gamestate_paused) {return false;}

        // Updates the avatar based on the input.
        switch(player_input) {
            case UP:
                // Looks if the input leads to a possible action.
                if (std::find(possible_actions.begin(), possible_actions.end(), legal_actions::UP) != possible_actions.end()) {
                    // Ensures that the movement doesn't cause the avatar to move out of the map.
                    if ((this->GetY()-1 >= 0) && (this->GetY()-1 < size.GetY())) {
                        // Updates the location of the player.
                        this->UpdateXY(this->GetX(), this->GetY()-1);

                        // Sets the variable to true so the loop ends.
                        action_is_legal = true;
                        
                    }
                }
                
                // Breaks out of the switch case.
                break;
            case DOWN:
                // Looks if the input leads to a possible action.
                if (std::find(possible_actions.begin(), possible_actions.end(), legal_actions::DOWN) != possible_actions.end()) {
                    // Ensures that the movement doesn't cause the avatar to move out of the map.
                    if ((this->GetY()+1 >= 0) && (this->GetY()+1 < size.GetY())) {
                        // Updates the location of the player.
                        this->UpdateXY(this->GetX(), this->GetY()+1);

                        // Sets the variable to true so the loop ends.
                        action_is_legal = true;
                        
                    }
                }

                // Breaks out of the switch case.
                break;
            case LEFT:
                // Looks if the input leads to a possible action.
                if (std::find(possible_actions.begin(), possible_actions.end(), legal_actions::LEFT) != possible_actions.end()) {
                    // Ensures that the movement doesn't cause the avatar to move out of the map.
                    if ((this->GetX()-1 >= 0) && (this->GetX()-1 < size.GetX())) {
                        // Updates the location of the player.
                        this->UpdateXY(this->GetX()-1, this->GetY());

                        // Sets the variable to true so the loop ends.
                        action_is_legal = true;
                        
                    }
                }

                // Breaks out of the switch case.
                break;
            case RIGHT:
                // Looks if the input leads to a possible action.
                if (std::find(possible_actions.begin(), possible_actions.end(), legal_actions::RIGHT) != possible_actions.end()) {
                    // Ensures that the movement doesn't cause the avatar to move out of the map.
                    if ((this->GetX()+1 >= 0) && (this->GetX()+1 < size.GetX())) {
                        // Updates the location of the player.
                        this->UpdateXY(this->GetX()+1, this->GetY());

                        // Sets the variable to true so the loop ends.
                        action_is_legal = true;
                        
                    }
                }

                // Breaks out of the switch case.
                break;
            case HEAL:
                // Looks if the input leads to a possible action.
                if (std::find(possible_actions.begin(), possible_actions.end(), legal_actions::HEAL) != possible_actions.end()) {
                    // Heals the teamates of the avatar.
                    for (auto game_object : game_objects) {
                        if (this->IsWereWolf() && game_object->GetGameObjectType() == WEREWOLF && !clock.IsDay()) {
                            // Downcasts the object to werewolf.
                            WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);

                            // Heals the object.
                            werewolf_ptr->UpdateHP(werewolf_ptr->GetMaximumHP());

                            // Sets the variable to true so the loop ends.
                            action_is_legal = true;

                            // Decreases the potion count of the avatar.
                            this->UpdatePotionCount(this->GetPotionCount()-1);
                        } else if (!this->IsWereWolf() && game_object->GetGameObjectType() == VAMPIRE && clock.IsDay()) {
                            // Downcasts the object to werewolf.
                            Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

                            // Heals the object.
                            vampire_ptr->UpdateHP(vampire_ptr->GetMaximumHP());

                            // Sets the variable to true so the loop ends.
                            action_is_legal = true;

                            // Decreases the potion count of the avatar.
                            this->UpdatePotionCount(this->GetPotionCount()-1);
                        }
                    }
                }

                // Breaks out of the switch case.
                break;
            case EXIT:
                // Exits the game.
                exit(0);
            case HELP:
                Input::PrintMessage(HELP);
                sleep(3);
                continue;
        }

        // Prints a message if the action is illegal.
        if (!action_is_legal) {std::cout<<"\n?? This Is Not A Legal Action ??\n\n";}
    } while (!action_is_legal);

    // Returns false if pause didn't happen.
    return false;
}