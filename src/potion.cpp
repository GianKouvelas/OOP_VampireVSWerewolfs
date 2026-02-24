// Dependencies.
#include <iostream>
#include "../include/potion.hpp"
#include "../include/gameobject.hpp"

///////////////////////////////////////////
//
// Potion's method implementations.
//
///////////////////////////////////////////

// Creates a potion object.
Potion::Potion() {
    this->used = false;
}

// Updates the potion coordinates.
void Potion::UpdatePotion(Point2D cords) {
    this->UpdateX(cords.GetX());
    this->UpdateY(cords.GetY());
}

// Returns true if the potion has been used.
bool Potion::IsUsed() {
    return this->used;
}

// Uses the potion.
void Potion::UsePotion() {
    this->used = true;
}

// Override the base function from the GameObject file,printing the P for the potion object.
void Potion::DrawGameObject() {
    std::cout << "\033[35mP\033[0m";
}

// Override the base function from the GameObject file,returning the enum type,which in this case the potion.
GAME_OBJECT_TYPE Potion::GetGameObjectType() {
    return POTION;
}

