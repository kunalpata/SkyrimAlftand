/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Dungeon class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Dungeon_hpp
#define Dungeon_hpp
#include "Space.hpp"

class Dungeon : public Space {
    
public:
    Dungeon();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Dungeon_hpp */
