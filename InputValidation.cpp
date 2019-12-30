/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Input Validation functions to check if user inputs are
 *                  valid.
 *****************************************************************************/

#include "InputValidation.hpp"
#include <iostream>

void inputValInt(int &input){
    
    int count = 0;
    
    while ((input < 1) || (input > 2) || std::cin.fail() || std::cin.get() != '\n') {
        count++;
        if (count == 1) {
            std::cout << "Dragonborn, please make the right selection.\n\n";
        }
        if (count == 2) {
            std::cout << "Use the keys on your primitive device to\n"
            << "select the correct option, dovhakiin.\n\n";
        }
        if (count >= 3) {
            std::cout << "Invalid entry, please try again.\n\n";
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter: ";
        std::cin >> input;
        std::cout << std::endl;
    }
    
}


void inputMaxValInt(int &input){
    
    while ((input < 1) || (input > 5) || std::cin.fail() || std::cin.get() != '\n') {
        std::cout << "Invalid entry, please try again.\n\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter: ";
        std::cin >> input;
        std::cout << std::endl;
    }
    
}



void inputValCompare(int &input, int min, int max) {
    while ((input < min) || (input > max) || std::cin.fail() || std::cin.get() != '\n') {
        std::cout << "Invalid entry, please try again.\n\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter: ";
        std::cin >> input;
        std::cout << std::endl;
    }
    
}


void inputSingle(int &input){
    
    
    while ((input < 0) || (input > 1) || std::cin.fail() || std::cin.get() != '\n') {
        std::cout << "Invalid entry, please try again.\n\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter: ";
        std::cin >> input;
        std::cout << std::endl;
    }
    
}


