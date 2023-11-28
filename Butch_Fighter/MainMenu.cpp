#include "MainMenu.h"

void Menu::displayMenu()
{
    sf::RenderWindow window(sf::VideoMode(1440, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Sprite background;
    sf::Texture texture1;

    texture1.loadFromFile("butch background.png");

    background.setTexture(texture1);
    background.setScale(10, 4);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.display();
    }
}
