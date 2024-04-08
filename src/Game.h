//
// Created by kiara on 4/3/2024.
//
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"
#ifndef COP3003PROJECT_GAME_H
#define COP3003PROJECT_GAME_H


class Game {

private:
    sf::RenderWindow* window;

    //Player
    Entity* entity;

    //Private Functions
    void initWindow();
    void initEntity();


public:
    Game();
    virtual ~Game();

    //Functions
    void runGame(); // this function is going to just run the game

    void update();
    void render();


};


#endif //COP3003PROJECT_GAME_H
