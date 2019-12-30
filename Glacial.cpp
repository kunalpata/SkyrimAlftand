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

#include "Glacial.hpp"

/**********************************************************
 * Description: Default constructor that sets the
 * directions to null and the name to the current room
 ***********************************************************/

Glacial::Glacial() {
    setNorth(nullptr);
    setSouth(nullptr);
    setEast(nullptr);
    setWest(nullptr);
    setName("Glacial Entrance");
}

/**********************************************************
 * Description: This function begans the introduction
 * and is the beginning dialogue of the entire game
 ***********************************************************/

bool Glacial::fight(Characters *f1, Characters *f2, Space* player, std::vector<string> &playerItem) {
    
    std::cout << f2->getName() << ": You there! Stop right there!\n"
    << "What are you doing in these ruins? Came here to\n"
    << "take my treasured goods huh? Well not today!\n"
    << "Today, you will pay! You will regret coming - \n\n";
    std::cout << "Press Enter\n";
    
    std::cin.ignore();
    
    std::cout << f2->getName() << ": AAAAAAGGHHH!!!\n\n";
    std::cout << "Press Enter\n";
    
    std::cin.ignore();
    
    std::cout << "*RUMBLE RUMBLE BOOOOM!!!*\n\n";
    
    std::cout << "The Bandit died from ice spikes and rocks!\n"
    << "You dodged an arrow on that one!\n\n";
    std::cout << "Press Enter\n";
    
    std::cin.ignore();
    
    return true;
    
}

/**********************************************************
 * Description: This states the goal of the game and
 * explains the user what they need to do and how to win
 ***********************************************************/

bool Glacial::roomChallenge(Space* player, std::vector<string> &playerItem) {
    
    std::cout << "You there, Dragonborn! You've just been trapped in the\n"
    << "ancient ruins of Alftand! This place was once thriving with Snow Elves,\n"
    << "until the Nords came in and wiped them all out! The remaining lived\n"
    << "underground for years and have transformed into something everyone avoids,\n"
    << "The Falmer. Hideous creatures, blind, but dangerous. You are at the heart of\n"
    << "their empire and you must find your way out! The Falmer isn’t the only thing\n"
    << "you should be aware about, the ruins are also filled with frostbite spiders and\n"
    << "bandits. Your objective, you must explore the ruins and defeat the Falmer that\n"
    << "is located in the last room to earn your freedom. Within the ruins are six\n"
    << "different rooms, each containing a key to go to the next, and to unlock the doors\n"
    << "to Skyrim and to win the game. You may collect items related to your journey such\n"
    << "as potions to heal your health by 10 points! You have only 6 steps to complete the\n"
    << "game so beware! Be on the lookout Dragonborn, and good luck, Skyrim is depending\n"
    << "on your survival.\n\n";
    
    std::cout << "Press Enter to continue\n";
    std::cin.ignore();
    
    std::cout << "The Lab Key has been added to your inventory!\n\n";
    player->addItem(playerItem, "Lab Key");
    
    std::cout << "A Potion has been added to your inventory!\n";
    player->addItem(playerItem, "Potion");
    
    return true;
}
