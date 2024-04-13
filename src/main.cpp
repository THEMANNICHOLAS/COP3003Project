#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Labyrinth.h"
#include "Entity.h"


int main() {
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


    sf::RenderWindow window(sf::VideoMode(1920,1080), "SFML PROJECT");
    window.setFramerateLimit(144);

    Game game(window);
    //Labyrinth map(window);

    sf::Event events;
    while(window.isOpen()){
        while (window.pollEvent(events)) {
            if (events.Event::type == sf::Event::Closed)             // if user click the 'X' it will close the window
                window.close();

            if (events.Event::key.code == sf::Keyboard::Escape)
                window.close();
        }

        game.runGame();

        //map.renderMap(window);

        window.clear();


    }















    return 0;
}