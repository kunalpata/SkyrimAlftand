/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for the Bandit class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Bandit_hpp
#define Bandit_hpp
#include "Characters.hpp"

class Bandit : public Characters {
    
public:
    Bandit();
    int attackChar();
    void defendChar(int);
    
};

#endif /* Bandit_hpp */
