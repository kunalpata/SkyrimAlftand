/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Glacial class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Glacial_hpp
#define Glacial_hpp
#include "Space.hpp"

class Glacial : public Space {
    
public:
    Glacial();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Glacial_hpp */
