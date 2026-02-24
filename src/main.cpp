// Dependencies.
#include "../include/game.hpp"
#include <iostream>
#include "unistd.h"
// The main function.
int main(void) {
    // Clears the terminal.
    system("clear");

    // Prints a greeting message.
    std::cout<<"!! The Game Will Start Shortly !!\n\n";

    // Pauses the program for 2 seconds.
    sleep(2);

    // Creates the initial state of the game.
    GameState game_state = GameState();

    // Runs the game.
    while(!game_state.IsGameOver()) {
        game_state.DrawGameState();
        game_state.UpdateGameState();
    }

    // Prints who won the game.
    game_state.PrintWinner();
    return 0;
}