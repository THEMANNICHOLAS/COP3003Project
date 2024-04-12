//
// Created by sting on 4/11/2024.
//

#include "Labyrinth.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <array>



/**
 * Default Constructor
 * Converts every cell in matrix array to enum Cell::Empty
 */


Labyrinth::Labyrinth() {

    mapSketch1 = {
            "****************************", //1
            "*            **            *", //2
            "* **** ***** ** ***** **** *", //3
            "*O**** ***** ** ***** ****O*", //4
            "* **** ***** ** ***** **** *", //5
            "*                          *", //6
            "* **** ** ******** ** **** *", //7
            "* **** ** ******** ** **** *", //8
            "*      **    **    **      *", //9
            "****** ***** ** ***** ******", //10
            "     * ***** ** ***** *     ", //11
            "     * **          ** *     ", //12
            "     * ** ******** ** *     ", //13
            "     * ** **2** ** ** *     ", //14
            "     *    ********    *     ", //15
            "     * ** *1** *** ** *     ", //16
            "     * ** ******** ** *     ", //17
            "     * **          ** *     ", //18
            "     * ** ******** ** *     ", //19
            "****** ** ******** ** ******", //20
            "*            **            *", //21
            "* **** ***** ** ***** **** *", //22
            "* **** ***** ** ***** **** *", //23
            "*   **       P        **   *", //24
            "*** ** ** ******** ** ** ***", //25
            "*** ** ** ******** ** ** ***", //26
            "*   **       **    **      *", //27
            "*O********** ** **********O*", //28
            "* ********** ** ********** *", //29
            "*                          *", //30
            "****************************", //31
    };
    //convertMap();
}

Labyrinth::Labyrinth(sf::RenderWindow &window) {
    _window = &window;
    mapSketch1 = {
            "****************************", //1
            "*            **            *", //2
            "* **** ***** ** ***** **** *", //3
            "*O**** ***** ** ***** ****O*", //4
            "* **** ***** ** ***** **** *", //5
            "*                          *", //6
            "* **** ** ******** ** **** *", //7
            "* **** ** ******** ** **** *", //8
            "*      **    **    **      *", //9
            "****** ***** ** ***** ******", //10
            "     * ***** ** ***** *     ", //11
            "     * **          ** *     ", //12
            "     * ** ***  *** ** *     ", //13
            "     * ** * 2    * ** *     ", //14
            "     *    *      *    *     ", //15
            "     * ** *1     * ** *     ", //16
            "     * ** ******** ** *     ", //17
            "     * **          ** *     ", //18
            "     * ** ******** ** *     ", //19
            "****** ** ******** ** ******", //20
            "*            **            *", //21
            "* **** ***** ** ***** **** *", //22
            "* **** ***** ** ***** **** *", //23
            "*   **       P        **   *", //24
            "*** ** ** ******** ** ** ***", //25
            "*** ** ** ******** ** ** ***", //26
            "*   **       **    **      *", //27
            "*O********** ** **********O*", //28
            "* ********** ** ********** *", //29
            "*                          *", //30
            "****************************", //31
    };
    mapArr[MAP_WIDTH][MAP_HEIGHT] = {0};
}

Labyrinth::~Labyrinth() = default;

void Labyrinth::initialize() {

}

void Labyrinth::load() {
    if(tileSheetTexture.loadFromFile("../assets/Map16.png")){
        std::cout << "Texture [Map16.png] loaded Successfully!" << std::endl;
        sprite.setTexture(tileSheetTexture);
        sprite.setScale(sf::Vector2f(2, 2));
    }
    else{
        std::cout << "ERROR: Texture could not be loaded." << std::endl;
    }
}

void Labyrinth::update() {
    render();
}


void Labyrinth::render() {

    //convertMap();

    for(int i=0; i<MAP_WIDTH; i++){
        for(int j=0; j<MAP_HEIGHT; j++){
            sprite.setPosition((CELL_SIZE * i*2)+480, (CELL_SIZE * j*2));

            switch(mapSketch1[j][i]) {
                case Cell::Wall:
                    checkWall(i, j);
                    _window->draw(sprite);
                    break;

                case Cell::Energizer: //energizer
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE,CELL_SIZE,CELL_SIZE, CELL_SIZE));
                    _window->draw(sprite);
                    break;

                case Cell::Pacman:
                    //put pacman here;
                    break;


            }
        }
    }
}

void Labyrinth::checkWall(int i, int j) {

    bool left {false};
    bool right {false};
    bool up {false};
    bool down {false};

    //Checks for every side of sprite
    if((mapSketch1[i][j] == mapArr[i][j+1]) && (mapSketch1[i][j] == mapArr[i][j-1])) {
        sprite.setTextureRect(sf::IntRect(9 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else{
        sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
    }
}

/*
void Labyrinth::convertMap() {
    for(int i = 0; i < MAP_WIDTH; ++i){
        for(int j = 0; j < MAP_HEIGHT; ++j){
            switch (mapSketch1[i][j]) {
                case(Sketch::Wall):
                    mapArr[i][j] = Cell::WallTile;
                    break;
                case(Sketch::Energizer):
                    mapArr[i][j] = Cell::EnergizerTile;
                    break;
                case(Sketch::Pacman):
                    mapArr[i][j] = Cell::PacmanSpawn;
                    break;

            }
        }
    }
}
*/

/*
void Labyrinth::print() {
    for(int i=0; i<MAP_HEIGHT; i++) {
        std::cout<<std::endl;
        for (int j = 0; j < MAP_WIDTH; j++) {
            std::cout << _map[i][j];
        }
    }
}
*/








