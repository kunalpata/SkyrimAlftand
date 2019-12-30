/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     This is the implementation file that uses the Characters
 *                  header file to implement the functions for the game. It
 *                  has a default constructor to initialize the member
 *                  variables. It also contains a functions to set the attack,
 *                  defense, armor, healthand name as well as getting them.
 *                  This is the base class for the other inherited classes
 *                  to implement the same functions as this class. It also
 *                  contains two pure virtual functions making this an
 *                  abstract class.
 *****************************************************************************/

#include "Characters.hpp"

/**********************************************************
 * Description: Default constructor initializes the
 * member variables.
 ***********************************************************/

Characters::Characters() {
    attack = 0;
    defend = 0;
    armor = 0;
    health = 0;
    charName = "";
    
}

/**********************************************************
 * Description: Set function that sets attack
 ***********************************************************/

void Characters::setAttack(int attack) {
    this -> attack = attack;
}

/**********************************************************
 * Description: Get function that gets attack
 ***********************************************************/

int Characters::getAttack() {
    return attack;
}

/**********************************************************
 * Description: Set function that sets defense
 ***********************************************************/

void Characters::setDefense(int defend) {
    this -> defend = defend;
}

/**********************************************************
 * Description: Get function that gets defense
 ***********************************************************/

int Characters::getDefense() {
    return defend;
}

/**********************************************************
 * Description: Set function that sets armor
 ***********************************************************/

void Characters::setArmor(int armor) {
    this -> armor = armor;
}

/**********************************************************
 * Description: Get function that gets armor
 ***********************************************************/

int Characters::getArmor() {
    return armor;
}

/**********************************************************
 * Description: Set function that sets health
 ***********************************************************/

void Characters::setHealth(int health) {
    this -> health = health;
}

/**********************************************************
 * Description: Get function that gets health
 ***********************************************************/

int Characters::getHealth() {
    return health;
}

/**********************************************************
 * Description: Set function that sets name
 ***********************************************************/

void Characters::setName(string charName) {
    this -> charName = charName;
}

/**********************************************************
 * Description: Get function that gets name
 ***********************************************************/

string Characters::getName() {
    return charName;
}

/**********************************************************
 * Description: This function recovers the player's health
 * by 10 points.
 ***********************************************************/

void Characters::recoverHealth(int recStr) {
    

    int heal = 10;
    
    recStr = recStr + heal;
    
    setHealth(recStr);
    
    if (getHealth() > 100) {
        setHealth(100);
    }

}
