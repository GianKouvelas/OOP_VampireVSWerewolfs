// Dependencies.
#include <iostream>
#include "../include/vampire.hpp"
#include "../include/werewolf.hpp"

///////////////////////////////////////////
//
// Vampire's method implementations.
//
///////////////////////////////////////////

// Creates a vampire object.
Vampire::Vampire() {
    this->hp=10; //Give him his health bar
    this->nums_of_heals=rand() % 3; //Gives heals between the number 0 and 2
    this->power=rand() % 3 + 1; //Gives the power random for the vampire between the number 1 and 3
    this->defence=rand() % 2 + 1; //Gives the defence random for the vampire between the number 1 and 2
    this->max_hp = hp;
}

// Returns the hp of the Vampire.
int Vampire::GetHP() {
    return this->hp;
}

// Returns the power of the werewolf.
int Vampire::GetPower() {
    return this->power;
}

// Returns the defence of the werewolf.
int Vampire::GetDefence() {
    return this->defence;
}

// Gets the maximum hp of the object.
int Vampire::GetMaximumHP() {
    return this->max_hp;
}

// Returns the number of health kits.
int Vampire::GetHealthKitCount() {
    return this->nums_of_heals;
}

// Updates the number of health kits.
void Vampire::UpdateHealthKitCount(int health_kit_count) {
    this->nums_of_heals = health_kit_count;   
}

// Updates the hp of the object.
void Vampire::UpdateHP(int hp) {
    this->hp=hp;
}

// Override the base function from the GameObject file,printing the V for vampire object.
void Vampire::DrawGameObject() {
    std::cout << "\033[31mV\033[0m";
}

// Override the base function from the GameObject file,returning the enum type,which in this case is vampire.
GAME_OBJECT_TYPE Vampire::GetGameObjectType() {
    return VAMPIRE;
}

// Updates the vampire.
bool Vampire::UpdateEntity(std::vector<GameObject*> game_objects, Size size) {

    // These variables are used to find the lagal movements of the avatar.
    bool is_up_right, is_up_left, is_down_left, is_down_right, can_attack, can_heal = false;
    
    // Eliminates any non legal moves.
    for (auto game_object : game_objects) {
        // Checks if there is an object next to the vampire.
        if (this->DoGameObjectsCollide(*game_object)) {
            // Checks if the object is an enemy object.
            if (game_object->GetGameObjectType() == WEREWOLF) {
                // Downcasts the game object.
                WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);

                // Checks if the vampire can attack the werewolf.
                if (werewolf_ptr->GetPower() <= this->GetPower()) {
                    werewolf_ptr->UpdateHP(werewolf_ptr->GetHP()-werewolf_ptr->GetDefence()-this->GetPower());
                    return false;
                }
            } else if (game_object->GetGameObjectType() == VAMPIRE) {
                // Downcasts the game object.
                Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

                // Checks if the ally can be healed.
                if ((vampire_ptr->hp != vampire_ptr->GetMaximumHP()) && (this->GetHealthKitCount() > 0)) {
                    // Heals the ally.
                    vampire_ptr->UpdateHP(vampire_ptr->GetMaximumHP());

                    // Decreases the health kit count of the werewolf.
                    this->UpdateHealthKitCount(this->GetHealthKitCount()-1);

                    // Returns false because the game wasn't paused.
                    return false;
                }
            }
            if (game_object->GetGameObjectType() != GROUND) {
                if ((game_object->GetX() < this->GetX()) && (game_object->GetY() < this->GetY())) {
                    is_up_left = true;
                } else if ((game_object->GetX() > this->GetX()) && (game_object->GetY() < this->GetY())) {
                    is_up_right = true;
                } else if ((game_object->GetX() > this->GetX()) && (game_object->GetY() > this->GetY())) {
                    is_down_right = true;
                } else if ((game_object->GetX() < this->GetX()) && (game_object->GetY() > this->GetY())) {
                    is_down_left = true;
                }
            }
        }
    }

    // Moves the werewolf to a random square.
    if ((rand()%4 == 1) && (!is_up_right) && ((this->GetY()-1 >= 0) && (this->GetX()+1 >= 0) && (this->GetY()-1 < size.GetY()) && (this->GetX()+1 < size.GetX()))) {
        this->UpdateXY(this->GetX()+1, this->GetY()-1);
    } else if ((rand()%4 == 1) && (!is_up_left) && ((this->GetY()-1 >= 0) && (this->GetX()-1 >= 0) && (this->GetY()-1 < size.GetY()) && (this->GetX()-1 < size.GetX()))) {
        this->UpdateXY(this->GetX()-1, this->GetY()-1);
    } else if ((rand()%4 == 2) && (!is_down_left) && ((this->GetY()+1 >= 0) && (this->GetX()-1 >= 0) && (this->GetY()+1 < size.GetY()) && (this->GetX()-1 < size.GetX()))) {
        this->UpdateXY(this->GetX()-1, this->GetY()+1);
    } else if ((rand()%4 == 3) && (!is_down_right) && ((this->GetY()+1 >= 0) && (this->GetX()+1 >= 0) && (this->GetY()+1 < size.GetY()) && (this->GetX()+1 < size.GetX()))) {
        this->UpdateXY(this->GetX()+1, this->GetY()+1);
    }

    // Returns false since the game is not paused.
    return false;
}