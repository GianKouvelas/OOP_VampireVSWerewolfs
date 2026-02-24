// Dependencies.
#include <iostream>
#include "../include/size.hpp"

///////////////////////////////////////////
//
// Size's method implementations.
//
///////////////////////////////////////////

// The default constructor.
Size::Size() {
    this->x = 5;
    this->y = 5;
}

// The constructor with the size of the grid as parameters. 
Size::Size(int x, int y) {
    this->x = x;
    this->y = y;
}

// Returns the x value.
int Size::GetX(){
    return this->x;
}

// Returns the y value.
int Size::GetY(){
    return this->y;
}

// Updates the size values of size.
void Size::UpdateSize(int x, int y) {
    this->x = x;
    this->y = y;
}
// Only used for debugging purposes.
void Size::Debug() {
    std::cout<<"The size is : "<<this->x<<" x "<<this->y<<"\n";
}
