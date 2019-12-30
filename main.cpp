/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     This is the main file that initializes the game. It asks
 *                  the user to enter their choice to play the game using the
 *                  menu function.
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

/**********************************************************
 * Description: The main function starts the entire game.
 * The purpose of this game is to have the player go
 * through each room that is a 2D linked list, connected
 * to each other, so the player can battle enemies and
 * solve the unique challenges they're presented with. The
 * player must survive and pass each challenge, giving them
 * the required key to move onto the next room and
 * eventually to the last room, where they fight the last
 * enemy and are able to win the game.
 ***********************************************************/

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    Game gamePlay;
    
    int menuChoice = menu();
    
    if (menuChoice == 1) {
        gamePlay.start();
    }
    
    else {
        std::cout << "Have a great day!\n";
    }
    
    
    return 0;
}
