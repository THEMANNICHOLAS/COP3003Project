#include <SFML/Graphics.hpp>

void userInput(sf::Keyboard);


int main() {
    auto window = sf::RenderWindow{{1920, 1080}, "COP3003 Project"};
    window.setFramerateLimit(144);

    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("C:\\Users\\sting\\repos\\COP3003Project\\assets\\apple.jpg");
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //Renders and shows object, constantly refreshing each frame
        window.clear();
        window.draw(sprite);
        window.display();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        }





    }
}