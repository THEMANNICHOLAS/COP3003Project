//
// Created by sting on 3/27/2024.
//
#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "GlobalConstants.h"

void drawMap(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& map, sf::RenderWindow& window){

    sf::Sprite sprite;
    sf::Texture texture;

    //texture.loadFromFile();
    //Add location for sprite texture when asset folder created
    //sprite.setTexture(texture);

    for(char a = 0; a < MAP_WIDTH; ++a){
        for(char b = 0; b < MAP_HEIGHT; ++b)
        {
            sprite.setPosition(static_cast<float> (CELL_SIZE * a) , static_cast<float>(CELL_SIZE * b));


            switch(map[a][b])
            {
                case(Cell::Energizer):
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE,CELL_SIZE, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);
                    break;
                    //Constructs a energizer pellet using Cell sizes

                case(Cell::Pellet):
                    sprite.setTextureRect(sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);
                    break;
                    //Constructs a pellet without needing
                case(Cell::Wall):
                    sprite.setTextureRect(sf::IntRect (CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);


                }
            }
        }
    }

bool mapCollision(bool collectPellets, short xCoord, short yCoord, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> & map){
    bool output = 0;

    //Getting precise cell location value, i.e cell 1, cell 2 etc.
    float cellX = xCoord/(CELL_SIZE);
    float cellY = yCoord/(CELL_SIZE);

    //char control for future use in switch statement
    //'for' loop to check all sides of Pac-Man
    for(char i = 0; i < 4; i++){
        short x = floor(cellX);
        short y = floor(cellY);
        if(MAP_HEIGHT>y && MAP_WIDTH>x && x>=0 && y>=0){

        }



    }

}