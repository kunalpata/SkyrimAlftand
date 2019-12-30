/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     This is the implementation file that uses the Space
 *                  header file to implement the functions for the game. It
 *                  has a default constructor to initialize the orientation
 *                  variables. It also contains a functions to set the
 *                  orientation and items as well as getting them.
 *                  This is the base class for the other inherited classes
 *                  to implement the same functions as this class. It also
 *                  contains two pure virtual functions making this an
 *                  abstract class.
 *****************************************************************************/

#include "Space.hpp"

/**********************************************************
 * Description: Default constructor initializes the
 * member variables.
 ***********************************************************/

Space::Space() {
    
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    
    roomName = "";
}

/**********************************************************
 * Description: Set function that sets north
 ***********************************************************/

void Space::setNorth(Space *north) {
    this -> north = north;
}

/**********************************************************
 * Description: Get function that gets north
 ***********************************************************/

Space* Space::getNorth() {
    return north;
}

/**********************************************************
 * Description: Set function that sets south
 ***********************************************************/

void Space::setSouth(Space *south) {
    this -> south = south;
}

/**********************************************************
 * Description: Get function that gets south
 ***********************************************************/

Space* Space::getSouth() {
    return south;
}

/**********************************************************
 * Description: Set function that sets east
 ***********************************************************/

void Space::setEast(Space *east) {
    this -> east = east;
}

/**********************************************************
 * Description: Get function that gets east
 ***********************************************************/

Space* Space::getEast() {
    return east;
}

/**********************************************************
 * Description: Set function that sets west
 ***********************************************************/

void Space::setWest(Space *west) {
    this -> west = west;
}

/**********************************************************
 * Description: Get function that gets west
 ***********************************************************/

Space* Space::getWest() {
    return west;
}

/**********************************************************
 * Description: Set function that sets name of orientation
 ***********************************************************/

void Space::setName(string roomName) {
    this -> roomName = roomName;
}

/**********************************************************
 * Description: Get function that gets name of orientation
 ***********************************************************/

string Space::getName() {
    return roomName;
}

/**********************************************************
 * Description: This function adds an item to the players
 * item container. It uses a vector and its member
 * functions to add the item to the front of the list
 ***********************************************************/

void Space::addItem(std::vector<string> &items, string itemName) {
    
    std::vector<string>::iterator addFront;
    addFront = items.begin();
    items.insert(addFront, itemName);
}

/**********************************************************
 * Description: This checks if a certain item exists. It
 * takes in a vector and string parameter to check the
 * item within the container so the player can use and to
 * check to go to the next room
 ***********************************************************/

bool Space::itemExists(std::vector<string> &items, string itemExists) {
    bool found = false;
    std::vector<string>::iterator searchItem;
    
    // iterate though the vector to check if the item exists
    searchItem = std::find(items.begin(), items.end(), itemExists);
    
    // if found return true
    if (searchItem != items.end()) {
        found = true;
    }
    
    return found;
}

/**********************************************************
 * Description: This prints all the items in the vector
 ***********************************************************/

void Space::printItems(std::vector<string> &items) {
    string str;
    
    std::cout << "\nInventory\n";
    std::cout << str.assign(10, '-') << std::endl;
    
    if (items.empty()) {
        std::cout << "Your inventory is empty.\n\n";
    }
    
    else {
        for (int i = 0; i < items.size(); i++) {
            std::cout << i + 1 << ") " << items[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

/**********************************************************
 * Description: This function has the player use a
 * specific item in their inventory. It takes a vector and
 * string parameter to check if the item exists. If the
 * item exits it removes it from the list if player chooses
 * to use it during the game
 ***********************************************************/

void Space::useItem(std::vector<string> &items, string getItem) {
    std::vector<string>::iterator searchItem;
    
    // iterate through the list
    searchItem = std::find(items.begin(), items.end(), getItem);
    
    // if the item exists removie it
    if (searchItem != items.end()) {
        std::cout << getItem << " used\n";
        items.erase(searchItem);
    }
    
    else {
        std::cout << "Not found\n";
    }
    
}
