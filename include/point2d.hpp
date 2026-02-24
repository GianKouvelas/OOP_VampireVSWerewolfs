// Include once.
#pragma once

// Dependencies.
#include <cmath>

// A class representing a 2D point.
class Point2D {
    private:
        // These integers represent the point.
        int x, y;
    public:
        // Creates a 2d point without arguments.
        Point2D();

        // Creates a 2d point with arguments.
        Point2D(int x, int y);

        // Updates the point object.
        void UpdatePoint2D(int x, int y);

        // Gets the x value of the point.
        int GetX();

        // Gets the y value of the point.
        int GetY();

        // Gets the distance of two points.
        double GetDistance(Point2D cords);
};