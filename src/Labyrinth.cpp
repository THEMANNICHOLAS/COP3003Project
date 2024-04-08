

#include "Labyrinth.h"
#include <iostream>
#include "GlobalConstants.h"
/**
 * I will ask the professor if these are viable constructors or not
 */

std::array<std::string, MAP_HEIGHT> mapSketch1{
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
        "     * ** **2**4** ** *     ", //14
        "     *    ********    *     ", //15
        "     * ** *1*3**** ** *     ", //16
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



/**
 * Default Constructor
 * Converts every cell in matrix array to enum Cell::Empty
 */

Labyrinth::Labyrinth() {
    convertMap(mapSketch1);
};


void Labyrinth::convertMap(std::array<std::string, MAP_HEIGHT> & map){

    for(unsigned char i=0; i<MAP_HEIGHT; i++) {
        for (unsigned char j = 0; j < MAP_WIDTH; j++) {

            //Makes every cell Empty
            this->_map[i][j] = Cell::Empty;

            switch (map[i][j]) {
                case '*':
                    this->_map[i][j] = Cell::Wall;
                    break;
                case ' ':
                    this->_map[i][j] = Cell::Empty;
                    break;
                case 'O':
                    this->_map[i][j] = Cell::Energizer;
                    break;
                case '1':
                    //will be ghost 1;
                    this->_map[i][j] = Cell::Empty;
                    break;
                case '2':
                    //will be ghost 2;
                    this->_map[i][j] = Cell::Empty;
                    break;
                case '3':
                    //will be ghost 3;
                    this->_map[i][j] = Cell::Empty;
                    break;
                case '4':
                    //will be ghost 4;
                    this->_map[i][j] = Cell::Empty;
                    break;
                case 'P':
                    //will be Pac-girly;
                    this->_map[i][j] = Cell::Empty;
                    break;
                default:
                    this->_map[i][j] = Cell::Wall;
            }
        }
    }
};


void Labyrinth::renderMap(sf::RenderWindow & window) {
    this->_texture.loadFromFile("../../assets/Map16.png");
    this->_sprite.setTexture(this->_texture);

    for(char i= 0; i < MAP_WIDTH; ++i){
        for(char j = 0; j < MAP_HEIGHT; ++j)
        {
            this->_sprite.setPosition(static_cast<float> (CELL_SIZE * i) , static_cast<float>(CELL_SIZE * j));


            switch(this->_map[i][j])
            {
                case(Cell::Energizer):

                    break;

                case(Cell::Pellet):
                    this->_sprite.setTextureRect(sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE));
                    window.draw(this->_sprite);
                    break;

                case(Cell::Wall):
                {
                    bool down{false};
                    bool left{false};
                    bool right{false};
                    bool up{false};

                    if(j < MAP_HEIGHT-1) {
                        if (Cell::Wall == this->_map[i][j + 1]) {down = true;}
                    }

                    if(i < 0){
                        if(Cell::Wall == this->_map[i-1][j]) {left = true;}
                    }
                    else {left = true;}

                    if(i < MAP_WIDTH-1){
                        if(Cell::Wall == this->_map[i+1][j]) {right = true;}
                    }
                    else {right = true;}

                    if(j > 0){
                        if(Cell::Wall == this->_map[i][j-1]) {up = true;}
                    }

                    this->_sprite.setTextureRect(sf::IntRect(CELL_SIZE * (down + 2 * (left + 2 * (right + 2 * up))), 0, CELL_SIZE, CELL_SIZE));
                }   window.draw(this->_sprite);
            }
        }
    }
}






