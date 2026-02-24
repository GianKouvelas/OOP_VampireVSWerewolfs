// Include once
#pragma once

// Dependencies
#include <iostream>
#include <stdlib.h>
#include "clock.hpp"
#include "size.hpp"
#include "map.hpp"
#include "input.hpp"
#include "entity.hpp"


// A class representing the game's state.
class GameState{
    private:
        // The dimensions of the grid.
        Size size;

        // A clock holding the time.
        Clock clock;

        // A boolean tracking if the game is paused.
        bool is_paused;

        // This represents the map of the game state.
        Map map;

        // Draws the info of the game state.
        void DrawGameStateInfo();
    public:
        // Creates the initial state of the game.
        GameState();

        // Returns the size of the game's field.
        Size GetSize();

        // Returns the clock of the game state.
        Clock GetClock();

        // Updates the clock of the game state.
        void UpdateClock();

        // Updates the size of the game's field.
        void UpdateSize(int x, int y);

        // Returns true if the game is paused.
        bool IsPaused();

        // Updates the state of the game.
        void UpdateGameState();

        // Returns true if the game is over.
        bool IsGameOver();

        // Draws the game state to the screen.
        void DrawGameState();

        // Prints the winner of the game.
        void PrintWinner();

        // Destroys the state of the game.
        ~GameState();
};