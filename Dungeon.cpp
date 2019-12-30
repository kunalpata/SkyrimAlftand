/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     This is the implementation file that uses the Space
 *                  virtual functions, and inherits from it as well. It
 *                  has a default constructor to initialize all the functions
 *                  that were inherited. It also contains the fight and
 *                  challenge functions. These functions are part of the room
 *                  challenge that allows the player to attack there opponent
 *                  and defend from an attack, as well as play the unique
 *                  room challenge.
 *****************************************************************************/

#include "Dungeon.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Dungeon::Dungeon() {
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Dungeon");
}

/**********************************************************
 * Description: Fight function takes in four parameters,
 * pointer objects of Characters type, using which
 * ever player is currently fighting, the player location
 * so it knows where the player is, and a vector that has
 * the players items which is passed by reference, to
 * items and to add new ones in. The fight goes on
 * until which ever player health is 0. During the fight,
 * the player is given the option to view the menu and to
 * fight or to view their inventory to restore health if
 * needed. It then checks to see if the player died and
 * returns false if they did to indicate the end of the
 * game.
 ***********************************************************/

bool Dungeon::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    
    bool ifPlayerDied = false;

    std::cout << "Oh no! There's a Frost Spider in this room. These\n"
    << "things are known to be viscous. I need to find away around\n"
    << "to avoid fighting it. I see a pillar ahead of me, I should try\n"
    << "to hide if I can.\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Note: You have a 20% chance of hiding.\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    int hide = rand() % 10 + 1;
    
    if (hide <= 2) {
        std::cout << "\nYou've hidden from the Frost Spider!\n\n";
    }
    
    else {
        std::cout << "The Frost Spider spotted you! Prepare for battle!\n\n";
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "\nGoal: Fight the Frost Spider and win.\n\n";
        std::cout << "Note: The Frost Spider has a 20% chance to use its frost bite ability\n"
        << "causing additional five points of damage if not blocking its attack.\n\n";
        
        string str;
        int itemChoice = 0;
        
        while (f1->getHealth() != 0 && f2->getHealth() != 0) {
            
            int fightChoice = fightMenu();
            
            if (fightChoice == 1) {
                // Player fights
                std::cout << f1->getName() << " attacks!\n";
                int fighter1Attack = f1->attackChar();
                std::cout << "HP: " << f1->getHealth() << std::endl << std::endl;
                
                // Enemy Defends
                std::cout << f2->getName() << " defends!\n";
                f2->defendChar(fighter1Attack);
                std::cout << "HP: " << f2->getHealth() << std::endl << std::endl;
                
                // check if enemy health is greater than 0 so it doesn't attack
                if (f2->getHealth() > 0) {
                    // Enemy fights
                    std::cout << f2->getName() << " attacks!\n";
                    int fighter2Attack = f2->attackChar();
                    std::cout << "HP: " << f2->getHealth() << std::endl << std::endl;
                    
                    // Player defends
                    std::cout << f1->getName() << " defends!\n";
                    f1->defendChar(fighter2Attack);
                    std::cout << "HP: " << f1->getHealth() << std::endl;
                }
                
                std::cout << str.assign(73, '-') << std::endl << std::endl;
            }
            
            
            if (fightChoice == 2) {
                player->printItems(playerItem);
                if (player->itemExists(playerItem, "Potion")) {
                    std::cout << "\nWould you like to use your potion?\n";
                    std::cout << "1) Yes\n";
                    std::cout << "2) No\n";
                    std::cout << "Enter: ";
                    std::cin >> itemChoice;
                    inputValInt(itemChoice);
                    
                    if (itemChoice == 1) {
                        // remove item
                        player->useItem(playerItem, "Potion");
                        // restore health 10 points
                        f1->recoverHealth(f1->getHealth());
                        std::cout << f1->getName() << " new strength: " << f1->getHealth() << std::endl << std::endl;
                    }
                    
                    else {
                        std::cout << "You did not use any items.\n\n";
                    }
                }
                
                else {
                    std::cout << "You can't use any items right now during the battle!\n\n";
                }
            }
        }
        
        if (f1->getHealth() == 0) {
            std::cout << f1->getName() << " died!\n";
            ifPlayerDied = true;
        }
    }
    
    return ifPlayerDied;
    
}

/**********************************************************
 * Description: This function takes in two parameters,
 * pointer object of Space type, so the player location
 * is know where the player is, and a vector that has
 * the players items which is passed by reference, to
 * items and to add new ones in. It presents the player a
 * unique challenge for them to solve and to move on to the
 * next room by adding the key to their inventory as well
 * as potions to restore their health if needed during
 * batttle.
 ***********************************************************/

bool Dungeon::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    std::cout << "What is this device? It looks like a mechanical box, wait it is!\n"
    << "It looks like it says something...\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "THIS DEVICE HOLDS THE KEY TO THE TOWER. GUESS THE NUMBER THIS\n"
    << "THIS BOX PRODUCES TO RETRIEVE THE KEY. YOU HAVE 5 TRIES. IF YOU GUESS\n"
    << "INCORRECTLY YOU WILL BE CRUSHED BY THE MIGHT OF THE CAVE OF ALFTAND!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Goal: For this game you must guess the correct\n"
    << "number between 1 and 10. If you don't guess it in five\n"
    << "tries or less, your fate is being crushed by a huge rock!\n\n";
    
    
    string str;
    int numberGuess = rand() % 10 + 1,
    playerNumber = 0,
    count = 0;
    
    bool correctGuess = false;
    
    std::cout << "Guess The Correct Number!\n";
    std::cout << str.assign(25, '-') << std::endl;
    
    
    while (numberGuess != playerNumber && count < 5) {
        std::cout << "Enter your guess: ";
        std::cin >> playerNumber;
        inputValCompare(playerNumber, 1, 10);
        count++;
        
        if (playerNumber < numberGuess) {
            std::cout << "Too low - try again.\n";
        }
        
        else if (playerNumber > numberGuess){
            std::cout << "Too high - try again.\n";
        }
        
        else{
            std::cout << "Congrats! You got it!\n";
            correctGuess = true;
            player->addItem(playerItem, "Tower Key");
            player->addItem(playerItem, "Potion");
            player->addItem(playerItem, "Potion");
            std::cout << "The Tower Key has been added to your inventory!\n";
            std::cout << "Two Potions have been added to your inventory!\n";
        }
    }
    

    if (correctGuess == false) {
        std::cout << "\nYou did not guess the correct numnber!\n"
        << "You are now doomed to being crushed by\n"
        << "the rocks of Alftand! Prepare to meet your doom!\n";
    }
    
    return correctGuess;
}
