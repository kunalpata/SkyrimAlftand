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

#include "Cathedral.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Cathedral::Cathedral() {
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Cathedral");
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

bool Cathedral::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    
    
    std::cout << "What is that stench!?\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();

    std::cout << "EEEEAAARRRKK...\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();

    std::cout << "Oh no, a Falmer. It's... hideous!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Falmer: EEAARRRK!?\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "It spotted me!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "You will die by my hands creature, and I will send you back to Oblivion!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Falmer: EEEEEAAARRRK!!\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "\nGoal: Fight the Falmer and open the door to your freedom!\n\n";
    std::cout << "Note: The Falmer has a 20% chance to use its frost ability\n"
    << "causing additional five points of damage if not blocking its attack.\n\n";
    
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
 * Description: This challenge function indicates the
 * end of the game and tells the player they won.
 ***********************************************************/

bool Cathedral::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    std::cout << "You've defeated the Falmer, you won! You are now free\n"
    << "to exit to Skyrim. Congratulations dovahkiin, it's time for\n"
    << "you to go face Alduin! Go out there, finish your quest, and\n"
    << "remember, Skyrim's fate depends on your hands!\n\n";
    
    std::cout << "Thank you for playing!\n";
    
    return true;
}


