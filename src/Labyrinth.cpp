//
// Created by sting on 4/11/2024.
//

#include "Labyrinth.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <array>



Labyrinth::Labyrinth(sf::RenderWindow &window) :
        _window{&window},
        mapSketch1  {
                "****************************",
                "*            **            *",
                "* **** ***** ** ***** **** *",
                "*O**** ***** ** ***** ****O*",
                "* **** ***** ** ***** **** *",
                "*                          *",
                "* **** ** ******** ** **** *",
                "* **** ** ******** ** **** *",
                "*      **    **    **      *",
                "****** ***** ** ***** ******",
                "     * ***** ** ***** *     ",
                "     * **          ** *     ",
                "     * ** ***  *** ** *     ",
                "     * ** * 2    * ** *     ",
                "     *    *      *    *     ",
                "     * ** *1     * ** *     ",
                "     * ** ******** ** *     ",
                "     * **          ** *     ",
                "     * ** ******** ** *     ",
                "****** ** ******** ** ******",
                "*            **            *",
                "* **** ***** ** ***** **** *",
                "* **** ***** ** ***** **** *",
                "*   ** **    P     ** **   *",
                "*** ** ** ******** ** ** ***",
                "*** ** ** ******** ** ** ***",
                "*            **            *",
                "*O********** ** **********O*",
                "* ********** ** ********** *",
                "*                          *",
                "****************************" }

{
    convertMap();
}

Labyrinth::~Labyrinth() = default;

void Labyrinth::convertMap() {
    for(int row = 0; row < MAP_WIDTH; ++row){
        for(int col = 0; col < MAP_HEIGHT; ++col){
            switch (mapSketch1[row][col]) {
                case(CellType::Wall):
                    cells[row][col].setCellType(CellType::Wall);
                    break;
                case('O'):
                    cells[row][col].setCellType(CellType::Energizer);
                    break;
                case('P'):
                    cells[row][col].setCellType(CellType::Pacman);
                    break;
                default:
                    cells[row][col].setCellType(CellType::Empty);
            }
        }
    }
}


void Labyrinth::initialize() {
    /*
    for(int row=0; row < MAP_HEIGHT; row++) {
        for (int col = 0; col < MAP_WIDTH; col++) {

            cells[row][col].setCellPosition(row, col);
            sprite.setPosition(cells[row][col].getCellPos());
        }
    }
     */
}

void Labyrinth::load() {
    if(tileSheetTexture.loadFromFile("../assets/Map16.png")){
        std::cout << "Texture [Map16.png] loaded Successfully!" << std::endl;
        sprite.setTexture(tileSheetTexture);
        sprite.setScale(sf::Vector2f(1, 1));
    }
    else{
        std::cout << "ERROR: Texture could not be loaded." << std::endl;
    }
}

void Labyrinth::update() {
    render();
}



void Labyrinth::render() {

    for(int row=0; row < MAP_HEIGHT; row++){
        for(int col=0; col < MAP_WIDTH; col++){

            cells[row][col].setCellPosition(row, col);
            sprite.setPosition(cells[row][col].getCellPos());

            switch(mapSketch1[row][col]) {
                case CellType::Wall:
                    checkWall(row, col);
                    _window->draw(sprite);
                    break;

                case CellType::Energizer: //energizer
                    sprite.setTextureRect(sf::IntRect(CELL_SIZE,CELL_SIZE,CELL_SIZE, CELL_SIZE));
                    _window->draw(sprite);
                    break;

                case CellType::Pacman:
                    //put pacman here;
                    break;


            }
        }
    }
}


void Labyrinth::checkWall(int row, int col) {

    if(row > 0){
        if(cells[row][col].getCellType() == cells[row-1][col].getCellType()){
            cells[row][col].setWalls(WallDirection::Up, true);
        }
    }
    if(row < MAP_HEIGHT-2){
        if(cells[row][col].getCellType() == cells[row+1][col].getCellType()){
             cells[row][col].setWalls(WallDirection::Down, true);
        }
    }
    if(col > 0){
        if(cells[row][col].getCellType() == cells[row][col-1].getCellType()){
            cells[row][col].setWalls(WallDirection::Left, true);
        }
    }
    if(col < MAP_WIDTH-2){
        if(cells[row][col].getCellType() == cells[row][col+1].getCellType()){
            cells[row][col].setWalls(WallDirection::Right, true);
        }
    }

    /*
    switch(cells->getWall(row, col)){
        case 1:
            sprite.setTextureRect(sf::IntRect(9*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 2:
            sprite.setTextureRect(sf::IntRect(12*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 3:
            sprite.setTextureRect(sf::IntRect(5*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 4:
            sprite.setTextureRect(sf::IntRect(3 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 5:
            sprite.setTextureRect(sf::IntRect(6 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 6:
            sprite.setTextureRect(sf::IntRect(10*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 7:
            sprite.setTextureRect(sf::IntRect(13 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 8:
            sprite.setTextureRect(sf::IntRect(6*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 9:
            sprite.setTextureRect(sf::IntRect(2*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        case 10:
            sprite.setTextureRect(sf::IntRect(6*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            break;
        default:
            sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
    }
*/

    if(cells[row][col].getWallType() == 1){
        sprite.setTextureRect(sf::IntRect(9*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 2){
        sprite.setTextureRect(sf::IntRect(12*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 3){
        sprite.setTextureRect(sf::IntRect(5*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 4) {
        sprite.setTextureRect(sf::IntRect(3 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 5) {
        sprite.setTextureRect(sf::IntRect(6 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 6){
        sprite.setTextureRect(sf::IntRect(10*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 7) {
        sprite.setTextureRect(sf::IntRect(13 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 8){
        sprite.setTextureRect(sf::IntRect(6*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 9){
        sprite.setTextureRect(sf::IntRect(2*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else if(cells[row][col].getWallType() == 10){
        sprite.setTextureRect(sf::IntRect(6*CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
    }
    else{
        sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
    }
} // checkWall















/*
void Labyrinth::print() {
    for(int i=0; i<MAP_HEIGHT; i++) {
        std::cout<<std::endl;
        for (int j = 0; j < MAP_WIDTH; j++) {
            std::cout << mapSketch1[i][j];
        }
    }
}
*/








