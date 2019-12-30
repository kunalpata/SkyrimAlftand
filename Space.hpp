/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for Space class. It contains the class
 *                  declarations as well as the member functions member
 *                  variables to implement.
 *****************************************************************************/

#ifndef Space_hpp
#define Space_hpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Characters.hpp"
#include "Menu.hpp"
#include "InputValidation.hpp"

using std::string;

class Space {
  
private:
    Space *north,
    *south,
    *east,
    *west;
    
    string roomName;
    
public:
    Space();
    // set orientation
    void setNorth(Space*);
    void setSouth(Space*);
    void setEast(Space*);
    void setWest(Space*);
    void setName(string);
    
    // get orientation
    Space *getNorth();
    Space *getSouth();
    Space *getEast();
    Space *getWest();
    string getName();
    
    // item functions
    void addItem(std::vector<string>&, string);
    bool itemExists(std::vector<string>&, string);
    void printItems(std::vector<string>&);
    void useItem(std::vector<string>&, string);
    
    // virtual functions
    virtual bool fight(Characters*, Characters*, Space*, std::vector<string> &playerItem) = 0;
    virtual bool roomChallenge(Space*, std::vector<string> &playerItem) = 0;
};

#endif /* Space_hpp */
