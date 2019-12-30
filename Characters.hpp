/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for Characters class. It contains the class
 *                  declarations as well as the member functions member
 *                  variables to implement.
 *****************************************************************************/

#ifndef Characters_hpp
#define Characters_hpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

class Characters {
  
private:
    int attack,
    defend,
    armor,
    health;
    
    string charName;
    
public:
    Characters();
    
    // set functions
    void setAttack(int);
    void setDefense(int);
    void setArmor(int);
    void setHealth(int);
    void setName(string);
    
    // get functions
    int getAttack();
    int getDefense();
    int getArmor();
    int getHealth();
    string getName();
    void recoverHealth(int);
    
    virtual int attackChar() = 0;
    virtual void defendChar(int) = 0;

    
};

#endif /* Characters_hpp */
