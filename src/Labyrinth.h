//
// Created by sting on 4/11/2024.
//

#ifndef CMAKESFMLMAP_LABYRINTH_H
#define CMAKESFMLMAP_LABYRINTH_H


#include <array>
#include <string>
#include "GLOBAL.h"
#include "SFML/Graphics.hpp"


class Labyrinth{
private:

    sf::Texture tileSheetTexture;
    std::array<std::string, MAP_HEIGHT> mapSketch1;
    sf::RenderWindow * _window;
    sf::Sprite sprite;

    int mapArr[MAP_WIDTH][MAP_HEIGHT];
    //std::vector<std::vector<int>> _map;

    //Private Functions:
    void render();
    void checkWall(int i, int j);
    //void convertMap();
    //void print();


public:

    //Constructors
    Labyrinth();
    Labyrinth(sf::RenderWindow & window);

    //Destructor
    ~Labyrinth();

    //Member Functions


    void initialize();
    void load();
    void update();
    void convertMap();

    void setWindow(sf::RenderWindow & window) {_window = &window;}
};



#endif //CMAKESFMLMAP_LABYRINTH_H
