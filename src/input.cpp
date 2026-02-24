// Dependencies.
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "../include/input.hpp"
#include "../include/size.hpp"

///////////////////////////////////////////
//                                       //
//    Input's method implementations.    //
//                                       //
///////////////////////////////////////////

// Prints a helpful message.
void Input::PrintHelp() {
    std::cout<<"\n!Useful Commands!"<<"\n\n";
    std::cout<<"UP"<<"\n"<<"DOWN"<<"\n"<<"LEFT"<<"\n"<<"RIGHT"<<"\n";
    std::cout<<"HEAL"<<"\n"<<"PAUSE"<<"\n"<<"EXIT";
    std::cout<<"!! Wait 2s before using another command !!\n\n";
}

std::string Input::InputConvert(std::string input) {

    ///////////////////////////////////////////
    //   This converts the string of every   //
    //   type of case to lowercase           //
    ///////////////////////////////////////////

    std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return std::tolower(c); });

    return input;

    ///////////////////////////////////////////
    //  This part of the code was taken      //
    //  from stackoverflow and it got        // 
    //  changed from the original            //
    ///////////////////////////////////////////

}

PlayerInput Input::GetInput() {
    std::string input;

    std::cout << "\033[97mUse A Command : ";
    std::cin >> input;

    input = InputConvert(input);

    if(input == "up") {
        return UP;
    }
    else if(input == "down") {
        return DOWN;
    }
    else if(input == "left") {
        return LEFT;
    }
    else if(input == "right") {
        return RIGHT;
    }
    else if(input == "heal") {
        return HEAL;
    }
    else if(input == "help") {
        return HELP;
    }
    else if(input == "size") {
        return MAP_SIZE;
    }
    else if(input == "team") {
        return AVATAR_TEAM;
    }
    else if(input == "pause") {
        return PAUSE;
    }
    else if(input == "exit") {
        return EXIT;
    }
    else {
        return INVALID;
    }
}


void Input::PrintMessage(PlayerInput player_input) {
    switch (player_input) {
    case HELP:
        PrintHelp();
        break;
    case MAP_SIZE:
        GetSize();
        break;
    case AVATAR_TEAM:
        GetAvatarTeam();
        break;
    }

}


bool Input::GetAvatarTeam() {
    std::string input;
    
    while(1) {
        std::cout << "\033[97m\nType either W / werewolf to join the werewolves or V / vampire to join the vampires : ";
        std::cin >> input;

        input = InputConvert(input);

        if(input == "w" || input == "werewolf") {
            return true;
        }
        else if(input == "v" || input == "vampire") {
            return false;
        }
        std::cout << "\033[97mThis team doesn't exist!" << std::endl;
    }

}


int Input::GetSize() {
    int input;

    while(1) {
        std::cout << "\033[97mGive a number between 3 and 15 (Make sure the number is odd) : ";
        std::cin >> input;
        if(input >= 3 && input <= 15 && input % 2 == 1) {
            return input;
        }
        else if(input > 15) {
            std::cout << "\033[97mYou can't have that big of a map!" << std::endl;
        }
        else if(input < 3) {
            std::cout << "\033[97mYou can't have that small of a map!" << std::endl;
        }
        else {
            std::cout << "\033[97mYou can't have a map with even dimensions" << std::endl;
        }
    }
}



