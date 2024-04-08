//
// Created by sting on 4/5/2024.
//

#ifndef CMAKESFMLPROJECT_LABYRINTH_H
#define CMAKESFMLPROJECT_LABYRINTH_H

#include <array>
#include "GlobalConstants.h"
#include "Pacman.h"

class Labyrinth {
private:
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> _map{};

public:
    //Constructors
    //------------
    Labyrinth();
    Labyrinth(std::array<std::string, MAP_HEIGHT> & map);


    //Getters-Setters
    //---------------
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> setMap(std::array<std::string, MAP_HEIGHT> & map);
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> getMap() {return _map;};





    //Member Functions
    //----------------
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convertMap(std::array<std::string, MAP_HEIGHT> map);
    void drawmap(sf::RenderWindow& window);


};


#endif //CMAKESFMLPROJECT_LABYRINTH_H
