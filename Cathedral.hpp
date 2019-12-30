/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Alftand class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Cathedral_hpp
#define Cathedral_hpp
#include "Space.hpp"

class Cathedral : public Space {
    
public:
    Cathedral();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Cathedral_hpp */
