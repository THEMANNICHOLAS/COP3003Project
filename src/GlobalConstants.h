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
constexpr unsigned char MAP_HEIGHT = 31;
constexpr unsigned char MAP_WIDTH = 28;




//Determines the cell Pac-Man is in
enum Cell{
    Empty,
    Energizer,
    Pellet,
    Wall
};














#endif //CMAKESFMLPROJECT_GLOBALCONSTANTS_H
