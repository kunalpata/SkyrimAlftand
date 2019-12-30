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

#include "Nord.hpp"

/**********************************************************
 * Description: Default constructor initializes the
 * member variables.
 ***********************************************************/

Nord::Nord() {
    setAttack(40);
    setDefense(10);
    setArmor(15);
    setHealth(100);
    setName("Nord");
    
    battleCry = 3;
}

/**********************************************************
 * Description: This function returns the attack of the
 * the player. It returns the attack number to pass to
 * the defenders defense function so it can calculate the
 * damage inflicted onto their enemy.
 ***********************************************************/

int Nord::attackChar() {
    
    int playerAttack = getAttack();
    
    return playerAttack;
}

/**********************************************************
 * Description: This function takes in an int parameter
 * that holds the attack number from the enemy. It takes
 * that number and calculates the correct damage inflicted
 * onto the player. If the player has a special ability, it
 * checks to if the player can use it.
 ***********************************************************/

void Nord::defendChar(int attacker) {
    
    // flag to check if player used ability
    bool usedAbility = false;
    
    if (battleCry > 0) {
        int abilityChoice;
        std::cout << "Would you like to use your special ability, Battle Cry?\n";
        std::cout << "1) Yes\n";
        std::cout << "2) No\n";
        std::cout << "Enter: ";
        std::cin >> abilityChoice;
        inputValCompare(abilityChoice, 1, 2);
        
        if (abilityChoice == 1) {
            attacker = 0;
            battleCry--;
            std::cout << "Battle Cry's left: " << battleCry << std::endl;
            usedAbility = true;
        }
    }
    
    // 50% chance to defend from player
    int randChance = rand() % 2 + 1;
    
    // if blocked then reduce health by only 2 points
    if (randChance == 1) {
        // check if player used ability
        if (usedAbility == true) {
            std::cout << "Nord used Battle Cry, no attack occurred!\n";
        }
        
        else {
            std::cout << getName() << " blocked attacked! Strength down two points\n";
            int reduceHealth = getHealth() - 2;
            
            if (reduceHealth > 0) {
                setHealth(reduceHealth);
            }
            
            if (reduceHealth <= 0) {
                setHealth(0);
            }
        }
    }
    
    // if not blocked then calculate total damage and health
    if (randChance == 2) {
        std::cout << getName() << " was hit!\n";

        // check if player used ability
        if (usedAbility == true) {
            std::cout << "Nord used Battle Cry, no attack occurred!\n";
        }
        
        else {
            int damage = attacker - getDefense() - getArmor();
            
            int newHealth = getHealth() - damage;
            
            // if health is still greater than 0 set it as updated health
            if (newHealth > 0) {
                setHealth(newHealth);
            }
            
            // if health is less than 0 set updated health to 0
            if (newHealth <= 0) {
                setHealth(0);
            }
        }
    }
}
