

#include "Labyrinth.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "GlobalConstants.h"
/**
 * I will ask the professor if these are viable constructors or not
 */


/**
 * Default Constructor
 * Converts every cell in matrix array to enum Cell::Empty
 */
Labyrinth::Labyrinth() {
    for (char i = 0; i < MAP_HEIGHT; ++i) {
        for (char j = 0; j < MAP_WIDTH; ++j) {

            _map[i][j] = Cell::Empty;    //Makes every cell in Map empty
        }
    }
};


/**
 *
 * @param map - map matrix with chars, is a sketch
 */
Labyrinth::Labyrinth(std::array<std::string, MAP_HEIGHT> & map) {
    _map = setMap(map);

}


/**
 *
 * @param map -
 * @return - takes std::array<std::string, MAP_WIDTH> map and returns
 * std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>
 */
std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> Labyrinth::convertMap(std::array<std::string, MAP_HEIGHT> map) {

    //Resulting map that will be returned
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> outputMap{};

    for(unsigned char i=0; i<MAP_HEIGHT; i++){
        for(unsigned char j=0; j<MAP_WIDTH; j++) {

            //Makes every cell Empty
            outputMap[i][j] = Cell::Empty;

            switch(map[i][j]){
                case '*':
                    outputMap[i][j] = Cell::Wall;
                    break;
                case ' ':
                    outputMap[i][j] = Cell::Empty;
                    break;
                case 'O':
                    outputMap[i][j] = Cell::Energizer;
                    break;
                case '1':
                    //will be ghost 1;
                    break;
                case '2':
                    //will be ghost 2;
                    break;
                case '3':
                    //will be ghost 3;
                    break;
                case '4':
                    //will be ghost 4;
                    break;
                case 'P':
                    //will be Pac-girly;
                    break;
                default:
                    map[i][j] = Cell::Wall;
            }
        }
    };
    return outputMap;
};


void Labyrinth::drawmap(sf::RenderWindow & window) {
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("..\\..\\..\\assets\\map16");
    sprite.setTexture(texture);

    for(char i= 0; i < MAP_WIDTH; ++i){
        for(char j = 0; j < MAP_HEIGHT; ++j)
        {
            sprite.setPosition(static_cast<float> (CELL_SIZE * i) , static_cast<float>(CELL_SIZE * j));


            switch(_map[i][j])
            {
                case(Cell::Energizer):
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);
                    break;

                case(Cell::Pellet):
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);
                    break;

                case(Cell::Wall):
                {
                    bool down{false};
                    bool left{false};
                    bool right{false};
                    bool up{false};

                    if(j < MAP_HEIGHT-1) {
                        if (Cell::Wall == _map[i][j + 1]) {down = true;}
                    }

                    if(i < 0){
                        if(Cell::Wall == _map[i-1][j]) {left = true;}
                    }
                    else {left = 1;}

                    if(i < MAP_WIDTH-1){
                        if(Cell::Wall == _map[i+1][j]) {right = true;}
                    }
                    else {right = true;}

                    if(j > 0){
                        if(Cell::Wall == _map[i][j-1]) {up = true;}
                    }

                    sprite.setTextureRect(sf::IntRect(CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0, CELL_SIZE, CELL_SIZE));
                    window.draw(sprite);

                }
            }
        }
    }
};


/**
 *
 * @param map - map matrix with chars, is a sketch
 * @return converted map from char sketch to enum Cell values
 */
std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> Labyrinth::setMap(std::array<std::string, MAP_HEIGHT> & map) {
    Labyrinth output;
    return output.convertMap(map);
};




