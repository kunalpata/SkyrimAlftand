/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for the Falmer class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Falmer_hpp
#define Falmer_hpp
#include "Characters.hpp"

class Falmer : public Characters {
    
private:
    int frost;
    
public:
    Falmer();
    int attackChar();
    void defendChar(int);

};

#endif /* Falmer_hpp */
