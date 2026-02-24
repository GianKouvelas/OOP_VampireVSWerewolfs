// Include once.
#pragma once

// A class representing the grid of a Game State.
    class Size{
        private:
            // The x and y values.
            int x,y;
        public:
            // The default constructor.
            Size();

            // The constructor with the size of the grid as parameters. 
            Size(int x, int y);

            // Returns the x value.
            int GetX();

            // Returns the y value.
            int GetY();

            // Updates the size values of size.
            void UpdateSize(int x, int y);

            // Only used for debugging purposes.
            void Debug();
    };