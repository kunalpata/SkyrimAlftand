/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/14/19
 * Description:     Header file for the Lab class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Lab_hpp
#define Lab_hpp
#include "Space.hpp"

class Lab : public Space {
    
public:
    Lab();
    bool fight(Characters*, Characters*, Space*, std::vector<string>&);
    bool roomChallenge(Space*, std::vector<string>&);
};

#endif /* Lab_hpp */
