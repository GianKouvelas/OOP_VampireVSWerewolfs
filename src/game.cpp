#include "../include/game.hpp"
#include <iostream>
#include <algorithm>

///////////////////////////////////////////
//                                       //
// Game States's method implementations. //
//                                       //
///////////////////////////////////////////

// Creates the initial state of the game.
GameState::GameState() {
    this->size = Size();
    this->clock = Clock();
    this->is_paused = false;
    
    // Gets the size of the map.
    int size = Input::GetSize();

    // Updates the size of the game.
    this->size.UpdateSize(size, size);
    
    // Creates a map for the game state.
    this->map = Map(this->size);

     // Sets the avatar's team.
    this->map.GetAvatar()->UpdateTeam(Input::GetAvatarTeam());
}

// Returns the size of the game's field.
Size GameState::GetSize() {
    return this->size;
}

// Returns the clock of the game state.
Clock GameState::GetClock() {
    return this->clock;
}

// Updates the clock of the game state.
void GameState::UpdateClock() {
    this->clock.UpdateClock();
}

// Updates the size of the game's field.
void GameState::UpdateSize(int x, int y) {
    this->size.UpdateSize(x, y);
}

// Returns true if the game is paused.
bool GameState::IsPaused(){
    return this->is_paused;
}

// Draws the game state to the screen.
void GameState::DrawGameState() {
    // Clears the console.
    system("clear");

    // Draws the map of the game state if the game is not paused.
    if (this->is_paused) {
        this->DrawGameStateInfo();
    } else {
        this->map.DrawMap(this->clock);
    }
}

// Returns true if the game is over.
bool GameState::IsGameOver() {
    // The game ends when one of the two teams has been eliminated.
    return (this->map.GetVampireCount() == 0) || (this->map.GetWereWolfCount() == 0);
}

// Updates the state of the game.
void GameState::UpdateGameState() {
    this->map.UpdateMap(this->clock, this->is_paused);
}

// Prints the winner of the game.
void GameState::PrintWinner() {
    // Only prints a winner if the game is over.
    if (this->IsGameOver() && (this->map.GetWereWolfCount() > this->map.GetVampireCount())) {
        system("clear");
        std::cout<<"\n\nWerewolves won the game!\n\n";
    } else if (this->IsGameOver() && (this->map.GetWereWolfCount() < this->map.GetVampireCount())) {
        system("clear");
        std::cout<<"\n\nVampires won the game!\n\n";
    }
}
// Draws the info of the game state.
void GameState::DrawGameStateInfo() {
    // Prints a decorative line.
    for (int i = 0; i < 20; i++) {
        std::cout<<"=";

        // Flushes the output stream.
        fflush(stdout);
    }

    // Prints the game info text.
    std::cout<<"!GAME INFO!";

    // Prints a decorative line.
    for (int i = 0; i < 20; i++) {
        std::cout<<"=";

        // Flushes the output stream.
        fflush(stdout);
    }

    // Adds two lines.
    std::cout<<"\n\n";

    // Prints the number of active vampires.
    std::cout<<"Number Of Active Vampires : " << this->map.GetVampireCount() <<"\n";

    // Prints the number of active werewolves.
    std::cout<<"Number Of Active WereWolves : " << this->map.GetWereWolfCount() <<"\n";

    // Prints the number of potions.
    std::cout<<"Number Of Potions : " << this->map.GetAvatar()->GetPotionCount() <<"\n";

    // Adds a line.
    std::cout<<'\n';

    // Prints a decorative line.
    for (int i = 0; i < 51; i++) {
        std::cout<<"=";

        // Flushes the output stream.
        fflush(stdout);
    }   

    // Prints info about the werewolves.
    std::cout<<"\n\nWereWolf Info :\n\n";

    int i = 1;
    for (auto game_object : this->map.GetGameObjects()) {
        // Checks that the game object is a werewolf.
        if (game_object->GetGameObjectType() == WEREWOLF) {
            // Downcasts the object.
            WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);
            // Prints info regarding the werewolf.

            // Prints the identifier of the werewolf.
            std::cout<<"W"<<i++<<":"<<"(x, y) = ("<<game_object->GetX()<<", "<<game_object->GetY()<<")";

            // Prints the hp of the werewolf.
            std::cout<<", "<<"HP : "<<werewolf_ptr->GetHP();

            // Prints the power of the werewolf.
            std::cout<<", "<<"Power : "<<werewolf_ptr->GetPower();

            // Prints the defence of the werewolf.
            std::cout<<", "<<"Defence : "<<werewolf_ptr->GetDefence();

            // Prints the health kit count.
            std::cout<<", "<<"Health Kit Count : "<<werewolf_ptr->GetHealthKitCount();

            // Changes line.
            std::cout<<"\n";
        }
    }

    // Changes line.
    std::cout<<"\n";

    // Prints a decorative line.
    for (int i = 0; i < 51; i++) {
        std::cout<<"=";
        fflush(stdout);
    }

    // Prints info about the vampires.
    std::cout<<"\n\nVampire Info :\n\n";

    i = 1;
    for (auto game_object : this->map.GetGameObjects()) {
        // Checks that the game object is a vampire.
        if (game_object->GetGameObjectType() == VAMPIRE) {
            // Downcasts the object.
            Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

            // Prints info regarding the vampire.

            // Prints the identifier of the vampire.
            std::cout<<"V"<<i++<<":"<<"(x, y) = ("<<game_object->GetX()<<", "<<game_object->GetY()<<")";

            // Prints the hp of the werewolf.
            std::cout<<", "<<"HP : "<<vampire_ptr->GetHP();

            // Prints the power of the vampire.
            std::cout<<", "<<"Power : "<<vampire_ptr->GetPower();

            // Prints the defence of the vampire.
            std::cout<<", "<<"Defence : "<<vampire_ptr->GetDefence();

            // Prints the health kit count.
            std::cout<<", "<<"Health Kit Count : "<<vampire_ptr->GetHealthKitCount();

            // Changes line.
            std::cout<<"\n";
        }
    }

    // Changes line.
    std::cout<<"\n";

    // Prints a decorative line.
    for (int i = 0; i < 51; i++) {
        std::cout<<"=";
        fflush(stdout);
    }

    // Changes line.
    std::cout<<"\n";
}

// Destroys the state of the game
GameState::~GameState() {
    
}