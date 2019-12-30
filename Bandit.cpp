/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     This is the implementation file that uses the Characters
 *                  virtual functions, and inherits from it as well. It
 *                  has a default constructor to initialize all the functions
 *                  that were inherited. It also contains the attack and
 *                  defense functions. These functions allow the player to
 *                  attack there opponent and defend from an attack.
 *****************************************************************************/

#include "Bandit.hpp"

/**********************************************************
 * Description: Default constructor initializes the
 * member variables.
 ***********************************************************/

Bandit::Bandit() {
    setAttack(30);
    setDefense(10);
    setArmor(10);
    setHealth(100);
    setName("Bandit");
    
}

/**********************************************************
 * Description: This function returns the attack of the
 * the player. It returns the attack number to pass to
 * the defenders defense function so it can calculate the
 * damage inflicted onto their enemy.
 ***********************************************************/

int Bandit::attackChar() {
    
    int playerAttack = getAttack();
    
    return playerAttack;
}

/**********************************************************
 * Description: This function takes in an int parameter
 * that holds the attack number from the enemy. It takes
 * that number and calculates the correct damage inflicted
 * onto the player.
 ***********************************************************/

void Bandit::defendChar(int attacker) {
    
    // 50% chance to defend from player
    int randChance = rand() % 2 + 1;
    
    // if blocked then reduce health by only 2 points
    if (randChance == 1) {
        std::cout << getName() << " blocked attacked! Strength down two points\n";
        int reduceHealth = getHealth() - 2;
        
        if (reduceHealth > 0) {
            setHealth(reduceHealth);
        }
        
        if (reduceHealth <= 0) {
            setHealth(0);
        }
    }
    
    // if not blocked then calculate total damage and health
    if (randChance == 2) {
        std::cout << getName() << " was hit!\n";
        
        int damage = attacker - getDefense() - getArmor();
        
        int newHealth = getHealth() - damage;
        
        // if health is still greater than 0 set it as updated health
        if (newHealth > 0) {
            setHealth(newHealth);
        }
        
        // if health is less than 0 set updated health to 0
        if (newHealth <= 0) {
            setHealth(0);
            std::cout << getName() << " dies!\n";
        }
    }
}

