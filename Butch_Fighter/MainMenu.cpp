#include "MainMenu.h"
 /*Menu::Menu(double width, double height)
{
     this->choices.loadFromFile("Brush King.ttf");


}
 Menu::~Menu()
 {

 }*/
void Menu::displayMenu()
{
    sf::RenderWindow window(sf::VideoMode(1440, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Sprite background;
    sf::Texture texture1;

    sf::Text MainTitle;

    texture1.loadFromFile("butch background.png");
    
    this->title.loadFromFile("Martyric_PersonalUse.ttf");
    MainTitle.setFont(title);
    MainTitle.setString("Butch Fighter");
    MainTitle.setCharacterSize(128);
    MainTitle.setFillColor(sf::Color::Red);
    MainTitle.setOutlineColor(sf::Color(128,128,128));
    MainTitle.setOutlineThickness(3);
    MainTitle.setPosition(384, 0);

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
        window.draw(MainTitle);
        window.display();
    }
}
