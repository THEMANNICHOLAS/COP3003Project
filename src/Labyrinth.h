//
// Created by sting on 4/5/2024.
//

#pragma once

#include <array>
#include "GlobalConstants.h"
#include <string>
#include "SFML/Graphics.hpp"


class Labyrinth {
private:

    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> _map{};
    sf::Texture _texture;
    sf::Sprite _sprite;

    void convertMap(std::array<std::string, MAP_HEIGHT> & map);

public:


    Labyrinth();





    //Member Functions

    void renderMap(sf::RenderWindow & window);

};


