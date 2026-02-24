// Include once.
#pragma once

// Dependencies.
#include <iostream>
#include <string>

// An enum holding values for the input of the player.
typedef enum {UP, DOWN, LEFT, RIGHT, HEAL, HELP, MAP_SIZE, AVATAR_TEAM, PAUSE, EXIT, INVALID} PlayerInput;

// A class holding useful methods for handling the player's input.
class Input {
    private:
        // Prints a helpful message.
        static void PrintHelp();
    public:
        // Returns the input of the player.
        static PlayerInput GetInput();

        // Prints messages regarding the player's input.
        static void PrintMessage(PlayerInput player_input);

        // Gets the team of the avatar.
        static bool GetAvatarTeam();

        // Gets the size of the map
        static int GetSize();

        //Converts the string from any character case to lowercase characters
        static std::string InputConvert(std::string input);
};