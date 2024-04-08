//
// Created by kiara on 4/3/2024.
//
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#ifndef COP3003PROJECT_ENTITY_H
#define COP3003PROJECT_ENTITY_H



class Entity {

private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;

    //Private Functions
    void initTexture();
    void initSprite();

public:
    Entity();
    virtual ~Entity();

   // float movementSpeed;

// Public Funtions

    void move(const float dirX, const float dirY );

    void update();
    void render(sf::RenderTarget& target);


};


#endif //COP3003PROJECT_ENTITY_H
