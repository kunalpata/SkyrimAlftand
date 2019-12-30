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

#include "Alftand.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Alftand::Alftand() {
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Alftand Main Hall");
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

bool Alftand::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    string str;
    int dialogue;
    
    std::cout << "Bandit: Hey! Who are you!? Where is the other guy!?\n"
    << "WHAT HAVE YOU DONE!?\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Choose what to say\n";
    std::cout << str.assign(20, '-') << std::endl;
    std::cout << "1) I don't know what you're talking about...\n";
    std::cout << "2) Oh, your Orc buddy? The other bandit? Eh, he was softer than a sweetroll.\n";
    std::cout << "Enter: ";
    std::cin >> dialogue;
    inputValInt(dialogue);

    if (dialogue == 1) {
        std::cout << "\nBandit: Yes you do! Liar! Prepare to meet your fait, in the ground!\n";
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "Goal: Fight the Bandit and win.\n\n";
    }
    
    if (dialogue == 2) {
        std::cout << "\nBandit: ARRRGGGHHHHH!\n";
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "*RUMBLE RUMBLE BOOOOM!!!*\n\n";
        
        std::cout << "Rocks are falling! The bandit pulled a lever for the trap!\n\n";
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "You quickly dodge them but weren't quick enough, your health went down 5 points!\n";
        
        int trap = f1->getHealth() - 5;
        f1->setHealth(trap);
        std::cout << "New Health: " << f1->getHealth() << std::endl << std::endl;
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "Bandit: Prepare to die!\n\n";
        
        std::cout << "Press Enter to continue\n";
        std::cin.ignore();
        
        std::cout << "Goal: Fight the bandit and win.\n\n";
    }
    
    // flag to check if player died
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

bool Alftand::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    string str;
    bool userAnswer = false;
    int choice = 0,
    count = 2;
    
    std::cout << "There is something written on the wall...\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Goal: Solve the riddle to unlock the key to the Dungeon.\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Solve This Riddle\n";
    std::cout << str.assign(17, '-') << std::endl;
    std::cout << "What can point in every direction but can't reach the destination by itself.\n";
    std::cout << "1) A compass\n";
    std::cout << "2) Your finger\n";
    std::cout << "3) A spoon\n";

    while (choice != 2 && count != 0) {
        std::cout << "Enter: ";
        std::cin >> choice;
        inputValCompare(choice, 1, 3);
        
        if (choice != 2) {
            std::cout << "\nWrong answer!\n";
            count--;
        }
        
        if (choice != 2 && count != 0) {
            std::cout << count << " guesse(s) left!\n\n";
        }
    }
    
    if (choice == 2) {
        std::cout << "You are correct!\n";
        userAnswer = true;
        player->addItem(playerItem, "Dungeon Key");
        player->addItem(playerItem, "Potion");
        player->addItem(playerItem, "Potion");
        std::cout << "The Dungeon Key has been added to your inventory!\n";
        std::cout << "Two Potions have been added to your inventory!\n";
    }
    
    return userAnswer;
    
}
