/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for the Nord class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Nord_hpp
#define Nord_hpp
#include "Characters.hpp"
#include "InputValidation.hpp"

class Nord : public Characters {
    
private:
    int battleCry;
    
public:
    Nord();
    int attackChar();
    void defendChar(int);
    
};

#endif /* Nord_hpp */
