//
// Created by kiara on 4/3/2024.
//

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


//Private Functions
/**
 *
 */
void Entity::initTexture()
{
    //load a texture from file

    if (!this->texture.loadFromFile("../../assets/PacGirlyLEFT.png") )
    {
        std::cout << "ERROR::ENTITY::INITTEXTURE::Could not load texture file" << std::endl ;
    }

}

void Entity::initSprite()
{
    //setting the texture for the sprite
    this->sprite.setTexture(this->texture); // takes  the reference of a texture

    //set position of the sprite everytime in the middle of the screen

    this->sprite.setPosition(960.f,540.f);

    //resize the sprite

    this->sprite.scale(.7f,.7f); // putting (1.f,1.f) is going to be the original size of the image



}


/**
 *  Constructor
 */
Entity::Entity()
{
    this->movementSpeed = 1.f;

    this->initTexture();
    this->initSprite();
}


Entity::~Entity() {

}


//Public Functions

/**
 *
 * @param dirX
 * @param dirY
 */
void Entity::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

}

/**
 *
 */
void Entity::update()
{

}


void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
