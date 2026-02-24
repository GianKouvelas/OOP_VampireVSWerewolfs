// Dependencies.
#include <iostream>
#include <math.h>
#include "../include/map.hpp"
#include <algorithm>

///////////////////////////////////////////
//
// Map's method implementations.
//
///////////////////////////////////////////

// Creates and places a potion on the ground.
void Map::CreateAndPlacePotion(int x, int y) {
    // Creates a potion object.
    Potion* potion_ptr = new Potion();

    // Sets the coordinates of the object.
    potion_ptr->UpdateXY(x, y);

    // Adds the potion to the vector holding the game objects.
    this->game_objects.push_back(potion_ptr);
}

// Creates and places the avatar to the map.
void Map::CreateAndPlaceAvatar(int x, int y) {
    // Creates an avatar object.
    Avatar* avatar_ptr = new Avatar();

    // Updates the avatar pointer.
    this->avatar_ptr = avatar_ptr;

    // Updates the default coordinates of the avatar.
    avatar_ptr->UpdateXY(x/2, y/2);

    // Inserts the avatar object to the vector.
    this->game_objects.push_back(avatar_ptr);
}

// Creates and places the werewolves to the map.
void Map::CreateAndPlaceWereWolves(Size size) {
    // The dimensions of the map.
    int x = size.GetX();
    int y = size.GetY();

    // Creates and places werewolves at the first rank of the map.
    for (int j = 0; j < x; j++) {
        // Makes it so werewolves have odd x values.
        if (j % 2 == 0) {
            // Creates a werewolf object.
            WereWolf* werewolf_ptr = new WereWolf();

            // Changes the default coordinates of the werewolf.
            werewolf_ptr->UpdateXY(0, j);

            // Adds the werewolf to the vector.
            game_objects.push_back(werewolf_ptr);
        }
    }
}

// Creates and places the vampires to the map.
void Map::CreateAndPlaceVampires(Size size) {
    // The dimensions of the map.
    int x = size.GetX();
    int y = size.GetY();

    // Creates and places ωαμπιρεσ at the λαστ rank of the map.
    for (int j = 0; j < x; j++) {
        // Makes it so vampires have odd x values.
        if (j % 2 == 0) {
            // Creates a vampire object.
            Vampire* vampire_ptr = new Vampire();

            // Changes the default coordinates of the vampire.
            vampire_ptr->UpdateXY(y-1, j);

            // Adds the werewolf to the vector.
            game_objects.push_back(vampire_ptr);
        }
    }
}

// Creates and places a ground object to the map.
void Map::CreateAndPlaceGround(int x,int y) {
    // Creates a ground object.
    Ground* ground_ptr = new Ground();

    // Updates the default coordinates of the ground object.
    ground_ptr->UpdateXY(x, y);

    // Inserts the ground object to the vector.
    this->game_objects.push_back(ground_ptr);
}

// Creates and places a tree object to the map.
void Map::CreateAndPlaceTree(int x, int y) {
    // Creates a tree object.
    Tree* tree_ptr = new Tree();

    // Updates the default coordinates of the ground object.
    tree_ptr->UpdateXY(x, y);

    // Inserts the ground object to the vector.
    this->game_objects.push_back(tree_ptr);
}

// Creates and places a river object to the map.
void Map::CreateAndPlaceRiver(int x, int y) {
    // Creates a river object.
    River* river_ptr = new River();

    // Updates the default coordinates of the river object.
    river_ptr->UpdateXY(x, y);

    // Inserts the river object to the vector.
    this->game_objects.push_back(river_ptr);
}

// Creates and places the other objects to the map.
void Map::CreateAndPlaceOthers(Size size) {
    // The dimensions of the map.
    int x = size.GetX();
    int y = size.GetY();

    // Sets the seed for rand.
    srand(time(NULL));

    // A variable used to tell if a potion has been placed.
    bool potion_placed = false;

    // Fills the unoccupied squares of the map
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            // Checks if a game object has these specific coordinates.
            bool found = false;
            for (auto game_object : this->game_objects) {
                if ((game_object->GetX() == i) && (game_object->GetY() == j)) {
                    found = true;
                    break;
                }
            }
            
            // Creates a ground object.
            CreateAndPlaceGround(i, j);

            // Checks if such a game object was found.
            if (!found) {

                // Generates a random number between 0 and 99.
                int num = (rand() % 100);
                
                if (!potion_placed) {
                    potion_placed = true;
                    CreateAndPlacePotion(i, j);
                } else if ((num >= 95) && (num <= 98)) {
                    // Creates a tree object.
                    CreateAndPlaceTree(i, j);
                } else if ((num >= 98) && (num <= 99)) {
                    // Creates a river object.
                    CreateAndPlaceRiver(i, j);
                }
            }
        }
    }
}

// Updates the game's map.
void Map::UpdateMap(Clock& clock, bool& is_paused) {
    // Finds the avatar object.
    Avatar* avatar_ptr = this->GetAvatar();

    // Pauses or UnPauses the gamestate.
    bool pause_happened = avatar_ptr->UpdateEntity(this->GetGameObjects(), this->map_size, is_paused, clock);

    // Pauses or UnPauses the gamestate.
    if (pause_happened) {
        is_paused = !is_paused;
        return;
    }

    // Does nothing if the game state is paused.
    if (!is_paused) {
        // Updates all the other game objects.
        for (auto game_object : this->GetGameObjects()) {
            // Updates the werewolf object.
            if (game_object->GetGameObjectType() == WEREWOLF) {
                // Downscasts the game object to werewolf.
                WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);

                // Updates the werewolf.
                werewolf_ptr->UpdateEntity(this->GetGameObjects(), this->map_size);
            } else if (game_object->GetGameObjectType() == VAMPIRE) {
                // Downscasts the game object to vampire.
                Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

                // Updates the werewolf.
                vampire_ptr->UpdateEntity(this->GetGameObjects(), this->map_size);
            }
        }
        // Updates the clock of the game.
        clock.UpdateClock();
    }

    // Cleans the vector of dead entities.
    for (auto game_object : this->GetGameObjects()) {
        if (game_object->GetGameObjectType() == VAMPIRE) {
            // Downscasts the game object to vampire.
            Vampire* vampire_ptr = dynamic_cast<Vampire*>(game_object);

            // Checks the hp of the vampire.
            if (vampire_ptr->GetHP() <= 0) {
                this->DeleteGameObject(vampire_ptr);
            }
        } else if (game_object->GetGameObjectType() == WEREWOLF) {
            // Downscasts the game object to vampire.
            WereWolf* werewolf_ptr = dynamic_cast<WereWolf*>(game_object);

            // Checks the hp of the vampire.
            if (werewolf_ptr->GetHP() <= 0) {
                this->DeleteGameObject(werewolf_ptr);
            }
        } else if (game_object->GetGameObjectType() == POTION) {
            // Downcasts the game object to potion.
            Potion* potion_ptr = dynamic_cast<Potion*>(game_object);

            // Checks that the potion has been used.
            if (potion_ptr->IsUsed()) {
                this->DeleteGameObject(potion_ptr);
            }
        }
    }
}


// Creates objects for the map.
void Map::FillMap(Size size) {
    // The dimensions of the map.
    int x = size.GetX();
    int y = size.GetY();

    // Creates and places the avatar to the map.
    CreateAndPlaceAvatar(x, y);

    // Creates and places the werewolves to the map.
    CreateAndPlaceWereWolves(this->map_size);

    // Creates and places the vampires to the map.
    CreateAndPlaceVampires(this->map_size);

    // Creates and places the other objects to the map.
    CreateAndPlaceOthers(this->map_size);
}

// Deletes an entity from the map.
void Map::DeleteGameObject(GameObject* game_object) {
    // Finds the location of the game object inside the vector.
    std::vector<GameObject*>::iterator it;
    it = std::find(this->game_objects.begin(), this->game_objects.end(), game_object);

    if (it != this->game_objects.end()) {
        this->game_objects.erase(it);
    }

    // Deletes the game object.
    delete game_object;
}

// Creates a map.
Map::Map() {
    // Sets the size to 9x9.
    this->map_size = Size();

    // Fills the map.
    FillMap(this->map_size);
}

// Creates a map with a predefined size.
Map::Map(Size size) {
    // Sets the size of the map.
    this->map_size = size;

    // Fills the map.
    FillMap(size);
}

// Draws the map to the screen.
void Map::DrawMap(Clock clock) {
    // Draws the clock.
    clock.DrawClock();

    // The dimensions of the map.
    int x = this->map_size.GetX();
    int y = this->map_size.GetY();
    
    // The dimensions of the board! (Not the size of the map)
    int board_x = 2*x+1;
    int board_y = 2*y+1;
    
    // Prints the board.
    for (int i = 0; i < board_x; i++) {
        for (int j = 0; j < board_y; j++) {
            if ((i%2 == 0) && (j%2 == 0)) {
                std::cout<<"\033[33m+\033[0m";
            } else if ((i%2 == 0) && (j%2 != 0)) {
                std::cout<<"\033[33m-\033[0m";
            } else if ((i%2 != 0) && (j%2 == 0)) {
                std::cout<<"\033[33m|\033[0m";
            } else {
                // This is used to print a game object that is not a ground object.
                bool found = false;

                // Prints any objects with these specific coordinates.
                for (auto game_object : this->game_objects) {
                    if (((game_object->GetX() == (j-1)/2) && (game_object->GetY() == (i-1)/2)) && (game_object->GetGameObjectType() != GROUND)) {
                        // A non ground object was found.
                        found = true;

                        // Draws the game object to the terminal.
                        game_object->DrawGameObject();

                        // Breaks out of the loop.
                        break;
                    }
                }

                // Prints a space character if non-ground object wasn't found.
                if (!found) {
                    std::cout<<" ";
                }
            }
        }
        
        // Goes to the next row of the board.
        std::cout<<"\n";
    }
}

// Returns the object present in the map.
std::vector<GameObject*> Map::GetGameObjects() {
    return this->game_objects;
}


// Gets the number of vampires.
int Map::GetVampireCount() {
    // Sets the vampire count to 0.
    int vampire_count = 0;

    // Searches for vampires.
    for (auto game_object : this->game_objects) {
        if (game_object->GetGameObjectType() == VAMPIRE) {
            vampire_count++;
        }
    }
    
    // Returns the number of active vampires.
    return vampire_count;
}

// Gets the number of werewolves.
int Map::GetWereWolfCount() {
    // Sets the vampire count to 0.
    int werewolf_count = 0;

    // Searches for werewolves.
    for (auto game_object : this->game_objects) {
        if (game_object->GetGameObjectType() == WEREWOLF) {
            werewolf_count++;
        }
    }
    
    // Returns the number of active werewolves.
    return werewolf_count;
}

// Returns a pointer to the avatar.
Avatar* Map::GetAvatar() {
    return this->avatar_ptr;
}

// Destroys a map.
Map::~Map() {

}