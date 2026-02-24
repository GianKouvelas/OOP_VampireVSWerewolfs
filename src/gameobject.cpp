#include "../include/gameobject.hpp"
#include <iostream>

///////////////////////////////////////////
//                                       //
// GameObject's method implementations.  //
//                                       //
///////////////////////////////////////////

// Creates a game object.
GameObject::GameObject() {
    // Sets the x,y values to 0.
    this->cords=Point2D(0,0);
}

// Returns the x value of the game object.
int GameObject::GetX() {
    return this->cords.GetX();
}

// Updates both the x and y value of the game object.
void GameObject::UpdateXY(int x, int y) {
    this->cords.UpdatePoint2D(x, y);
}

// Returns the y value of the game object.
int GameObject::GetY() {
    return this->cords.GetY();
}

// Updates the x value of the game object.
void GameObject::UpdateX(int x) {
    this->cords.UpdatePoint2D(x,this->cords.GetY());
}

// Updates the y value of the game object.
void GameObject::UpdateY(int y) {
    this->cords.UpdatePoint2D(this->cords.GetX(),y);
}

// Returns true if two game object collide.
bool GameObject::DoGameObjectsCollide(GameObject game_object) {
    return (this->cords.GetDistance(game_object.cords) <= sqrt(2));
}

// Returns the type of the game object.
GAME_OBJECT_TYPE GameObject::GetGameObjectType() {
    return GAME_OBJECT;
}

// Draws the game object.
void GameObject::DrawGameObject() {
    std::cout<<"O";
}