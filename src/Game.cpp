//
// Created by kiara on 4/3/2024.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Labyrinth.h"





/**
 * Private Function
 */
void Game::initWindow() {

    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "GAME PRACTICE"); // sf::Style::Close |sf::Style::Titlebar);
    this->_window->setFramerateLimit(144); // setting framerate, locked to 144
    this->_window->setVerticalSyncEnabled(false);

}


void Game::initEntity() // keep everything related to the entity in here
{
    this->entity = new Entity(); // keeps this empty because the player constructor is empty

}


void Game::initMap() {
    this->labyrinth = new Labyrinth();



}



//Constructors & Destructors

/**
 * constructor
 */
Game::Game()
{
    this->initWindow();
    this->initEntity();
    this->initMap();


}

/**
 *
 */
Game::~Game()
{
    delete this->_window;
    delete this->entity;
    delete this->labyrinth;
}

/**
 *
 */
void Game::runGame()
{
    while(this->_window->isOpen())
    {
        this->update();
        this->render();
        this->labyrinth;
    }
}


/**
 * updates all the positions
 */
void Game::update() {


    sf::Event events{};
    while (this->_window->pollEvent(events))
    {
        if(events.Event::type == sf::Event::Closed)             // if user click the 'X' it will close the window
            this->_window->close();

        if( events.Event::key.code == sf::Keyboard::Escape)
            this->_window->close();
    }

    //Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //MOVE LEFT
        this->entity->move(-1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // MOVE RIGHT
        this->entity->move(1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //MOVE UP
        this->entity->move(0.f, -1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // MOVE DOWN
        this->entity->move(0.f, 1.f);

}


/**
 * draws all the stuff out
 */
void Game::render()
{
    this->_window->clear();



    //Draws all the stuff
    this-> entity->render(*this->_window); // it takes a reference, since the window is a pointer
                                            // it needs to be dereference out window by the asterisk (*)


    this->_window->display();

}

