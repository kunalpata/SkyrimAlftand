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

#include "Lab.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Lab::Lab() {
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Alchemy Lab");
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

bool Lab::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    
    std::cout << "Bandit: Halt! Who goes there?\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Bandit: What are you doing here!? Come to scavenge\n"
    << "my treasure, aren't you? I will not have it...\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Bandit: Come to think of it, your head would look good mounted\n"
    << "on my wall, prepare to die!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Goal: Fight the Bandit and win.\n\n";
    
    string str;
    bool ifPlayerDied = false;
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
        
        // TODO: implement inventory function here to open items
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

bool Lab::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    
    
    bool userAnswer = false;
    string str;
    int choice = 0,
    count = 2;
    
    std::cout << "There is something written on the wall...\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Goal: Solve the riddle to unlock the key to the Main Hall.\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Solve This Riddle\n";
    std::cout << str.assign(17, '-') << std::endl;
    std::cout << "What can't be burned in fire, nor drowned in water?\n";
    std::cout << "1) Ice\n";
    std::cout << "2) Sand\n";
    std::cout << "3) Rock\n";

    while (choice != 1 && count != 0) {
        std::cout << "Enter: ";
        std::cin >> choice;
        inputValCompare(choice, 1, 3);
        
        if (choice != 1) {
            std::cout << "\nWrong answer!\n";
            count--;
        }
        
        if (choice != 1 && count != 0) {
            std::cout << count << " guesse(s) left!\n\n";
        }
    }
    
    if (choice == 1) {
        std::cout << "You are correct!\n";
        userAnswer = true;
        player->addItem(playerItem, "Main Hall Key");
        std::cout << "The Main Hall Key has been added to your inventory!\n";
    }
    
    return userAnswer;
    
}

