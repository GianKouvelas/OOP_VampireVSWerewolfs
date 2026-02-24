#include "../include/point2d.hpp"
#include <iostream>

///////////////////////////////////////////
//
// Point2D's method implementations.
//
///////////////////////////////////////////

// Creates a 2d point without arguments.
Point2D::Point2D() {
    this->x = 0;
    this->y = 0;
}

// Creates a 2d point with arguments.
Point2D::Point2D(int x, int y) {
    this->x = x;
    this->y = y;
}

// Updates the point object.
void Point2D::UpdatePoint2D(int x, int y) {
    this->x = x;
    this->y = y;
}

// Gets the x value of the point.
int Point2D::GetX() {
    return this->x;
}

// Gets the y value of the point.
int Point2D::GetY() {
    return this->y;
}

// Gets the distance of two points.
double Point2D::GetDistance(Point2D cords) {
    return sqrt(pow(this->x-cords.GetX(), 2)+pow(this->y-cords.GetY(), 2));
}
