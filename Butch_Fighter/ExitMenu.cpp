#include "ExitMenu.h"

/*
    Function: ExitMenu()
    Description: it sets all of the shapes and words to the right colors, size, and font
    */
ExitMenu::ExitMenu()
{
    exit_menu.setSize(sf::Vector2f(800, 400));
    exit_menu.setFillColor(sf::Color(255, 255, 255, 120));
    exit_menu.setOutlineColor(sf::Color(128, 128, 128));
    exit_menu.setOutlineThickness(5);
    exit_menu.setPosition(sf::Vector2f(320, 150));

    //setting the color and position of the boxes
    boxes[0].setSize(sf::Vector2f(200, 100));
    boxes[1].setSize(sf::Vector2f(200, 100));
    boxes[0].setFillColor(sf::Color::Red);
    boxes[1].setFillColor(sf::Color(128, 128, 128));
    boxes[0].setPosition(sf::Vector2f(455, 400));
    boxes[1].setPosition(sf::Vector2f(805, 400));
    boxes[0].setOutlineColor(sf::Color::Black);
    boxes[1].setOutlineColor(sf::Color::Black);
    boxes[0].setOutlineThickness(3);
    boxes[1].setOutlineThickness(3);

    //loading the font 
    font.loadFromFile("Brush King.otf");

    //are you sure you want to exit text 
    words[0].setString("Are you sure you want to Exit");
    words[0].setFont(font);
    words[0].setFillColor(sf::Color::Red);
    words[0].setPosition(340, 200);

    //yes text 
    words[1].setString("Yes");
    words[1].setFont(font);
    words[1].setFillColor(sf::Color::White);
    words[1].setPosition(515, 435);

    //no text
    words[2].setString("No");
    words[2].setFont(font);
    words[2].setFillColor(sf::Color::White);
    words[2].setPosition(875, 435);

    boxnumber = 0;
}

/*
    Fucntion: ~ExitMenu()
    Description: the destructor for the  ExitMenu class
    */
ExitMenu::~ExitMenu()
{

}

/*
    Function:displayExitMenu()
    Description: displays the exit menu
    */
void ExitMenu::displayExitMenu(sf::RenderWindow& window)
{
    int selected = 0;
    sf::Event event;
    while (selected == 0)
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                    moveleft();
                    //std::cout << "moving left" << std::endl;
                    break;
                case sf::Keyboard::A:
                    moveleft();
                    //std::cout << "moving left" << std::endl;
                    break;
                case sf::Keyboard::Right:
                    moveRight();
                    //std::cout << "moving right" << std::endl;
                    break;
                case sf::Keyboard::D:
                    moveRight();
                   // std::cout << "moving right" << std::endl;

                    break;
                case sf::Keyboard::Enter:
                    switch (GetBoxNumber())
                    {
                    case 0:
                        window.close();
                        selected = 1;
                        break;
                    case 1:
                        selected = 1;
                    }
                }
            }
        }

        window.draw(exit_menu);
        drawChoices(window);
        window.display();
    }
}

/*
    Funciton: drawChoices();
    Description: draws the title and the choices for the exit menu
    */
void ExitMenu::drawChoices(sf::RenderWindow& window)
{
    for (int i = 0; i < 2; ++i)
    {
        window.draw(boxes[i]);
    }
    for (int j = 0; j < 3; ++j)
    {
        window.draw(words[j]);
    }
}


/*
    Function: moveright();
    Description: moves your choice to the right
    */
void ExitMenu::moveRight()
{
    if (boxnumber + 1 < 2)
    {
        boxes[boxnumber].setFillColor(sf::Color(128, 128, 128));
        boxnumber++;
        boxes[boxnumber].setFillColor(sf::Color::Red);
        std::cout << "moving right" << std::endl;
    }
}

/*
Function: moveleft();
Description: moves your choice to the left
*/
void ExitMenu::moveleft()
{
    if (boxnumber - 1 >= 0)
    {

        boxes[boxnumber].setFillColor(sf::Color(128, 128, 128));
        boxnumber--;
        boxes[boxnumber].setFillColor(sf::Color::Red);
        std::cout << "moving left" << std::endl;
    }
}

/*
    Function GetBoxNumber
    Description: gets the number of the box that it is currently on;
    */
int ExitMenu::GetBoxNumber()
{
    return boxnumber;
}