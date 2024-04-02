/************************************************
 * file: GameState.h
 * dev:
 * desc: Header file for GameState. Use to
 * declare class and associated members and
 * data-types
 ***********************************************/

#ifndef CMAKESFMLPROJECT_GAMESTATE_H
#define CMAKESFMLPROJECT_GAMESTATE_H
#include "SFML/Graphics.hpp"

/*Class 'GameState' will determine current game state, whether the game is over, continuing,
 location of Pac-Man, keys pressed, and more.*/


class GameState {
private:
    bool gameOver;
    virtual void keyPressed(char key) = 0;
    virtual bool isEnergized() = 0; //Virtual function for both Pac-Man and Ghost classes






};









#endif //CMAKESFMLPROJECT_GAMESTATE_H
