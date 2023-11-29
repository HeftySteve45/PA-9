#include "MainMenu.h"
 Menu::Menu()
{
     choices.loadFromFile("Brush King.otf");

     //play 
     MainMenu[0].setFont(choices);
     MainMenu[0].setFillColor(sf::Color(128,128,128));
     MainMenu[0].setString("Play");
     MainMenu[0].setCharacterSize(50);
     MainMenu[0].setPosition(50, 220);

     //controls 
     MainMenu[1].setFont(choices);
     MainMenu[1].setFillColor(sf::Color::Black);
     MainMenu[1].setString("Controls");
     MainMenu[1].setCharacterSize(50);
     MainMenu[1].setPosition(50, 370);

     //exit
     MainMenu[2].setFont(choices);
     MainMenu[2].setFillColor(sf::Color::Black);
     MainMenu[2].setString("Exit");
     MainMenu[2].setCharacterSize(50);
     MainMenu[2].setPosition(50, 520);
}

 Menu::~Menu()
 {

 }
void Menu::displayMenu()
{
    Menu mainmenu;
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
    MainTitle.setCharacterSize(120);
    MainTitle.setFillColor(sf::Color::Red);
    MainTitle.setOutlineColor(sf::Color(128,128,128));
    MainTitle.setOutlineThickness(3);
    MainTitle.setPosition(384, 0);

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
       
        for (int i = 0; i < 3; i++)
        {
            window.draw(MainMenu[i]);
        }
        window.display();
    }
}
