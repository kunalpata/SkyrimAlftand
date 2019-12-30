/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Tower class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Tower_hpp
#define Tower_hpp
#include "Space.hpp"

class Tower : public Space {
    
public:
    Tower();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Tower_hpp */
