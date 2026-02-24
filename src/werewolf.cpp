// Dependencies.
#include <iostream>
#include "../include/werewolf.hpp"
#include "../include/vampire.hpp"
///////////////////////////////////////////
//
// Werewolf's method implementations.
//
///////////////////////////////////////////

// Creates a werewolf object.
WereWolf::WereWolf() {
    this->hp=10; //Give him his health bar
    this->nums_of_heals=rand() % 3; //Gives heals between the number 0 and 2
    this->power=rand() % 3 + 1; //Gives the power random for the werewolf between the number 1 and 3
    this->defence=rand() % 2 + 1; //Gives the defence random for the werewolf between the number 1 and 2
    this->max_hp = this->hp; // Sets the maximum hp of the object.
}

// Returns the hp of the Werewolf.
int WereWolf::GetHP() {
    return this->hp;
}

// Returns the number of health kits.
int WereWolf::GetHealthKitCount() {
    return this->nums_of_heals;
}

// Updates the number of health kits.
void WereWolf::UpdateHealthKitCount(int health_kit_count) {
    this->nums_of_heals = health_kit_count;   
}

// Updates the hp of the object.
void WereWolf::UpdateHP(int hp) {
    this->hp=hp;
}

// Returns the maximum hp of the object.
int WereWolf::GetMaximumHP() {
    return this->max_hp;
}

// Returns the defence of the object.
int WereWolf::GetDefence() {
    return this->defence;
}

// Returns the power of the werewolf.
int WereWolf::GetPower() {
    return this->power;
}

// Override the base function from the GameObject file,printing the W for werewolf object.
void WereWolf::DrawGameObject() {
    std::cout << "\033[36mW\033[0m";
}

// Override the base function from the GameObject file,returning the enum type,which in this case is werewolf.
GAME_OBJECT_TYPE WereWolf::GetGameObjectType() {
    return WEREWOLF;
}

// Updates the werewolf.
bool WereWolf::UpdateEntity(std::vector<GameObject*> game_objects, Size size) {
    // These variables are used to find the lagal movements of the avatar.
    bool is_up, is_down, is_left, is_right, can_attack, can_heal = false;
    
    // Eliminates any non legal moves.
    for (auto game_object : game_objects) {
        // Checks if there is an object next to the werewolf.
        if (this->DoGameObjectsCollide(*game_object)) {
            if (game_object->GetGameObjectType() == VAMPIRE) {
                // Downcasts the game object.
                Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

                // Checks if the werewolf can attack the vampire.
                if (vampire_ptr->GetPower() <= this->GetPower()) {
                    vampire_ptr->UpdateHP(vampire_ptr->GetHP()-vampire_ptr->GetDefence()-this->GetPower());
                    return false;
                }
            } else if (game_object->GetGameObjectType() == WEREWOLF) {
                // Downcasts the game object.
                WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);

                // Checks if the ally can be healed.
                if ((werewolf_ptr->hp != werewolf_ptr->GetMaximumHP()) && (this->GetHealthKitCount() > 0)) {
                    // Heals the ally.
                    werewolf_ptr->UpdateHP(werewolf_ptr->GetMaximumHP());

                    // Decreases the health kit count of the werewolf.
                    this->UpdateHealthKitCount(this->GetHealthKitCount()-1);

                    // Returns false because the game wasn't paused.
                    return false;
                }
            } 
            if (game_object->GetGameObjectType() != GROUND) {
                if ((game_object->GetX() == this->GetX()) && (game_object->GetY() < this->GetY())) {
                    is_up = true;
                } else if ((game_object->GetX() == this->GetX()) && (game_object->GetY() > this->GetY())) {
                    is_down = true;
                } else if ((game_object->GetX() > this->GetX()) && (game_object->GetY() == this->GetY())) {
                    is_right = true;
                } else if ((game_object->GetX() < this->GetX()) && (game_object->GetY() == this->GetY())) {
                    is_left = true;
                }
            }
        }
    }

    // Moves the werewolf to a random square.
    if ((rand()%4 == 0) && (!is_up) && ((this->GetY()-1 >= 0) && (this->GetY()-1 < size.GetY()))) {
        this->UpdateY(this->GetY()-1);
    } else if ((rand()%4 == 1) && (!is_down) && ((this->GetY()+1 >= 0) && (this->GetY()+1 < size.GetY()))) {
        this->UpdateY(this->GetY()+1);
    } else if ((rand()%4 == 2) && (!is_left) && ((this->GetX()-1 >= 0) && (this->GetX()-1 < size.GetX()))) {
        this->UpdateX(this->GetX()-1);
    } else if ((rand()%4 == 3) && (!is_right) && ((this->GetX()+1 >= 0) && (this->GetX()+1 < size.GetX()))) {
        this->UpdateX(this->GetX()+1);
    }

    // Returns false since the game is not paused.
    return false;
}
