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

#include "Tower.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Tower::Tower(){
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Ruined Tower");
}

/**********************************************************
 * Description: Fight function returns true since there
 * isn't a enemy in this room
 ***********************************************************/

bool Tower::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    
    return false;
    
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

bool Tower::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    string str;
    bool userAnswer = false;
    int choice = 0,
    count = 3;
    
    std::cout << "There is something written on the wall...\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Goal: Solve the riddle to unlock the key to the Cathedral.\n\n";
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "Solve This Riddle\n";
    std::cout << str.assign(17, '-') << std::endl;
    std::cout << "A Bosmer, was slain. The Altmer claims the Dunmer is guilty.\n"
    << "The Dunmer says the Khajiit did it. The Orc swears he didn't kill the\n"
    << "Bosmer. The Khajiit says the Dunmer is lying. If only one of these speaks\n"
    << "the truth, who killed the Bosmer? You have three tries.\n";
    std::cout << "1) The Altmer\n";
    std::cout << "2) The Dunmer\n";
    std::cout << "3) The Khajiit\n";
    std::cout << "4) The Orc\n";
    
    while (choice != 4 && count != 0) {
        std::cout << "Enter: ";
        std::cin >> choice;
        inputValCompare(choice, 1, 4);
        
        if (choice != 4) {
            std::cout << "\nWrong answer!\n";
            count--;
        }
        
        if (choice != 4 && count != 0) {
            std::cout << count << " guesse(s) left!\n\n";
        }
    }
    
    if (choice == 4) {
        std::cout << "You are correct!\n";
        userAnswer = true;
        player->addItem(playerItem, "Cathedral Key");
        player->addItem(playerItem, "Potion");
        player->addItem(playerItem, "Potion");
        std::cout << "The Cathedral Key has been added to your inventory!\n";
        std::cout << "Two Potions have been added to your inventory!\n";
    }
    
    return userAnswer;
}
