/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Alftand class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Alftand_hpp
#define Alftand_hpp
#include "Space.hpp"

class Alftand : public Space {
  
public:
    Alftand();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Alftand_hpp */
