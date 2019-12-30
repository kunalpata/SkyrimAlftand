/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for the Spider class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Spider_hpp
#define Spider_hpp
#include "Characters.hpp"

class Spider : public Characters {
    
private:
    int frostBite;
    
public:
    Spider();
    int attackChar();
    void defendChar(int);
    
};


#endif /* Spider_hpp */
