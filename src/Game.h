//
// Created by kiara on 4/3/2024.
//

#pragma once

#include "Labyrinth.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"

class Game{

private:
    //Player
    Entity * entity;
    Labyrinth * labyrinth;

    //Private Functions
    void initWindow();
    void initEntity();
    void initMap();

protected:
    sf::RenderWindow * _window;
public:
    Game();
    virtual ~Game();

    //Functions
    void runGame(); // this function is going to just run the game

    void update();
    void render();


};



