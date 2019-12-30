/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     This is the implementation file that uses the Game class
 *                  functions. It initializes the players choice of
 *                  characters and starts the game, having each of the
 *                  characters fighting each other.
 *****************************************************************************/

#include "Game.hpp"

/**********************************************************
 * Description: Constructor that intializes the players
 * and enemies.
 ***********************************************************/

Game::Game() {
    
    dragonBorn = &nordPlayer;
    enemy1 = &falmerPlayer;
    enemy2 = &spiderPlayer;
    enemy3 = &banditPlayer;
    enemy4 = &bandit2Player;
    
    setupRooms();
    
}

/**********************************************************
 * Description: This function links all the room together.
 * The set up is linear, and the rooms will always point
 * east to the next room. The other directions not in use
 * point to null.
 ***********************************************************/

void Game::setupRooms() {
    glEntrance.setEast(&alchemyLab);
    alchemyLab.setEast(&mainHall);
    mainHall.setEast(&dunRoom);
    dunRoom.setEast(&towRoom);
    towRoom.setEast(&catroom);
}

/**********************************************************
 * Description: Room function takes in four parameters,
 * pointer objects of Characters type, using which
 * ever player is currently fighting, the player location
 * so it knows where the player is, and a vector that has
 * the players items which is passed by reference, to
 * items and to add new ones in. This function uses the
 * the fight and challenge functions from each room,
 * depending on which one the player is in. It also checks
 * to see if the player died to end the game and if the
 * challenge was completed to exit the while loop. It
 * gives the option to go to the next room but won't let
 * the user go if they don't have the key.
 ***********************************************************/

bool Game::roomSequences(Characters *p1, Characters *p2, Space *pLocation, std::vector<string> &pItems) {
    
    bool gameEnd = false,
    challengeEnd = false;
    
    std::cout << "Room: " << pLocation->getName() << std::endl;
    
    if (pLocation->getName() != "Cathedral") {
        std::cout << "Next Room: " << pLocation->getEast()->getName() << std::endl << std::endl;
    }
    
    while (challengeEnd == false) {
        
        int choice = roomMenu();
        
        if (choice == 1) {
            // fight the enemy in this room
            pLocation->fight(p1, p2, pLocation, pItems);
            
            // if the player survived
            if (p1->getHealth() != 0) {
                // if they pass the challenge
                if (pLocation->roomChallenge(pLocation, pItems) == true) {
                    if (pLocation->getName() != "Cathedral") {
                        std::cout << "\nProceeding to the next room.\n\n";
                    }
                    challengeEnd = true;
                }
                else {
                    // game over
                    gameEnd = true;
                    challengeEnd = true;
                }
            }
            
            // if player died
            else {
                // game over
                gameEnd = true;
                challengeEnd = true;
            }
        }
        
        // check if the player has the key to go ot next room
        if (choice == 2) {
            if (pLocation->itemExists(pItems, "Hall Key") != true) {
                std::cout << "You need a key to enter the next room!\n\n";
            }
        }
    }
    
    return gameEnd;
    
}


/**********************************************************
 * Description: The start function starts the entire game.
 * It allows the player to navigate through the map,
 * interact and fight their enemies, and get items and to
 * store them into their inventories. It starts the player
 * off in the glacial entrance and checks if the game has
 * been won or not.
 ***********************************************************/

void Game::start() {
    
    int steps = 6;
    int i = 0;
    
    // check to see if game is over
    bool gameOver = false;
    
    // check to see if it's the last room
    bool endRoom = false;
    
    // array to change the enemies in each room
    Characters *enemies[5] = {enemy3, enemy4, enemy2, enemy3, enemy1};
    
    // container for items
    std::vector<string> items;
    
    // Starting at the glacial entrance
    playerLocation = &glEntrance;
    
    std::cout << "Room: Glacial Entrance\n";
    std::cout << "Next Room: " << playerLocation->getEast()->getName() << std::endl;
    std::cout << "Steps: " << steps << std::endl << std::endl;
    
    playerLocation->fight(dragonBorn, enemy3, playerLocation, items);
    // present goal
    playerLocation->roomChallenge(playerLocation, items);
    playerLocation = playerLocation->getEast();
    steps--;
    
    while (gameOver == false && endRoom == false && steps > 0) {
        
        std::cout << "\nSteps Remaining: " << steps << std::endl << std::endl;
        
        if (roomSequences(dragonBorn, enemies[i], playerLocation, items) == false) {
            
            /* this checks if it's not last room so it doesn't increase or
             decrease any variables as well as set the player to a new
             location unnecessarily */
            if (playerLocation->getName() != "Cathedral") {
                i++;
                steps--;
                playerLocation = playerLocation->getEast();
                endRoom = false;
            }
            
            else {
                endRoom = true;
            }
        }
        
        else {
            gameOver = true;
            std::cout << "You Lost!\n";
        }
    }
}
