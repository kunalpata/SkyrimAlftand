/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Menu function that prompts user to start or end
 *                  game.
 *****************************************************************************/


#include "Menu.hpp"
#include "InputValidation.hpp"
#include <iostream>
#include <string>

using std::string;

int menu() {
    
    int choice,
    userChoiceMain = 0;
    
    std::cout << R"(
    ███████╗██╗  ██╗██╗   ██╗██████╗ ██╗███╗   ███╗
    ██╔════╝██║ ██╔╝╚██╗ ██╔╝██╔══██╗██║████╗ ████║
    ███████╗█████╔╝  ╚████╔╝ ██████╔╝██║██╔████╔██║
    ╚════██║██╔═██╗   ╚██╔╝  ██╔══██╗██║██║╚██╔╝██║
    ███████║██║  ██╗   ██║   ██║  ██║██║██║ ╚═╝ ██║
    ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝     ╚═╝
    
    )" << '\n';
    
    std::cout << "Welcome to Skyrim: The Ruins of Alftand!\nPlease select from the following options:\n";
    std::cout << "Press 1) Play Game.\n";
    std::cout << "Press 2) Quit\n\n";
    std::cout << "Enter: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    inputValInt(choice);
    
    if (choice == 1) {
        userChoiceMain = 1;
        return userChoiceMain;
    }
    
    if (choice == 2) {
        userChoiceMain = 2;
        return userChoiceMain;
    }
    
    return userChoiceMain;
}

// fight menu option when battling
int fightMenu() {
    
    int choice = 0,
    userChoiceMain = 0;
    
    string str;
    
    std::cout << "Options\n";
    std::cout << str.assign(10, '-') << std::endl;
    std::cout << "1) Fight\n";
    std::cout << "2) Inventory\n";
    std::cout << "Enter: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    inputValCompare(choice, 1, 2);
    
    
    if (choice == 1) {
        userChoiceMain = 1;
        return userChoiceMain;
    }
    
    if (choice == 2) {
        userChoiceMain = 2;
        return userChoiceMain;
    }
    
    return userChoiceMain;
}

int roomMenu() {
    
    int choice = 0,
    userChoiceMain = 0;
    
    string str;
    
    std::cout << "Options\n";
    std::cout << str.assign(10, '-') << std::endl;
    std::cout << "1) Explore\n";
    std::cout << "2) Go to next room\n";
    std::cout << "Enter: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    inputValCompare(choice, 1, 2);
    
    
    if (choice == 1) {
        userChoiceMain = 1;
        return userChoiceMain;
    }
    
    if (choice == 2) {
        userChoiceMain = 2;
        return userChoiceMain;
    }
    
    return userChoiceMain;
}
