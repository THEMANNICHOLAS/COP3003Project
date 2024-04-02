/************************************************
 file: GlobalConstants.h
 dev:
 desc: file to hold global variables used across
 classes, header files, and C++ files
***********************************************/
#pragma once
#ifndef CMAKESFMLPROJECT_GLOBALCONSTANTS_H
#define CMAKESFMLPROJECT_GLOBALCONSTANTS_H

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char MAP_HEIGHT = 31; // 31 Cells High, not pixel value
constexpr unsigned char MAP_WIDTH = 28; // 28 Cells wide, not pixel value




//Determines the cell Pac-Man is in
enum Cell{
    Empty,
    Energizer,
    Pellet,
    Wall
};














#endif //CMAKESFMLPROJECT_GLOBALCONSTANTS_H
