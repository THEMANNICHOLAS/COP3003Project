//
// Created by sting on 4/11/2024.
//

#ifndef CMAKESFMLMAP_GLOBAL_H
#define CMAKESFMLMAP_GLOBAL_H

constexpr unsigned int CELL_SIZE = 16; //Each cell is 16x16 pixels of Map16
constexpr unsigned int MAP_HEIGHT = 31; // 31 Cells High, not pixel value
constexpr unsigned int MAP_WIDTH = 28; // 28 Cells wide, not pixel value





enum Cell{ //Enumerator for use in map creation
    Empty = ' ',
    Energizer = 'O',
    Pellet = ' ',
    Wall = '*',
    Pacman = 'P',
    Ghost1 = '1',
    Ghost2 = '2',
};


#endif //CMAKESFMLMAP_GLOBAL_H
