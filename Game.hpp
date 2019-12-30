/******************************************************************************
 * Program Name:    Final Project (Skyrim: The Journey of Alftand)
 * Author:          Kunal Patadia
 * Date:            3/9/19
 * Description:     Header file for the Game class. It contains the
 *                  class declarations as well as the member functions
 *****************************************************************************/

#ifndef Game_hpp
#define Game_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Characters.hpp"
#include "Nord.hpp"
#include "Falmer.hpp"
#include "Spider.hpp"
#include "Bandit.hpp"
#include "Space.hpp"
#include "Glacial.hpp"
#include "Alftand.hpp"
#include "Lab.hpp"
#include "Dungeon.hpp"
#include "Tower.hpp"
#include "Cathedral.hpp"


class Game {
    
private:
    Characters *dragonBorn,
    *enemy1,
    *enemy2,
    *enemy3,
    *enemy4;
    
    // player and enemy objects
    Nord nordPlayer;
    Falmer falmerPlayer;
    Spider spiderPlayer;
    Bandit banditPlayer;
    Bandit bandit2Player;
    
    // player location
    Space *playerLocation;
    
    // Room objects, 6 rooms
    Glacial glEntrance;
    Lab alchemyLab;
    Alftand mainHall;
    Dungeon dunRoom;
    Tower towRoom;
    Cathedral catroom;
    
public:
    Game();
    void start();
    void setupRooms();
    bool roomSequences(Characters*, Characters*, Space*, std::vector<string> &);
    
    
};

#endif /* Game_hpp */
