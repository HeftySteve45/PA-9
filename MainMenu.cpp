#include "MainMenu.h"

/*
    Function: Menu()
    Description: is the default constructor and sets the array up with the buttons for the main menu selection
    */
 Menu::Menu()
{
     choices.loadFromFile("Brush King.otf");

     //play 
     MainMenu[0].setFont(choices);
     MainMenu[0].setFillColor(sf::Color::Red);
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

     selectedItem = 0;
}
 /*
    Funciton: ~Menu()
    Description: the default constructor for the main menu so it closes the window
    */
 Menu::~Menu()
 {
     
 }

 /*
    Function: displayMenu()
    Description: it displays the menu with the background and the choices
    */
void Menu::displayMenu()
{
    Menu mainmenu;
    ExitMenu exit;
    
    sf::RenderWindow window(sf::VideoMode(1440, 768), "Butch Fighter!", sf::Style::None);
    window.setFramerateLimit(60);//cap frame rate to 60 frames per second
    sf::Sprite background;
    sf::Texture texture1;
    sf::Text MainTitle;

    texture1.loadFromFile("butch background.png");
    
    this->title.loadFromFile("Martyric_PersonalUse.ttf");
    MainTitle.setFont(title);
    MainTitle.setString("Butch Fighter");
    MainTitle.setCharacterSize(120);
    MainTitle.setFillColor(sf::Color::Red);
    MainTitle.setOutlineColor(sf::Color::Black);
    MainTitle.setOutlineThickness(4);
    MainTitle.setPosition(384, 0);

    background.setTexture(texture1);
    background.setScale(10, 4);

    while (window.isOpen())
    {
        playMenuMusic();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveup();
                    break;
                case sf::Keyboard::Down:
                    movedown();
                    break;
                case sf::Keyboard::W:
                    moveup();
                    break;
                case sf::Keyboard::S:
                    movedown();
                    break;
                case sf::Keyboard::Escape:
                    std::cout << "in the exit menu" << std::endl;
                    exit.displayExitMenu(window);
                    break;
                case sf::Keyboard::Enter:
                    switch (getpressedItem())
                    {
                    case 0:
                        window.clear();
                        std::cout << "Playing the game" << std::endl; 
                        stopMenuMusic();
                        PlayGame(window);
                        break;
                    case 1:
                        window.clear();
                        stopMenuMusic();
                        controls.ControlScreen(window);
                        std::cout << "control menu" << std::endl;

                        break;
                    case 2:
                        std::cout << "Closing the widnow and exiting the game" << std::endl;
                        stopMenuMusic();
                        exit.displayExitMenu(window);
                        break;
                    }
                    break;
                }
                break;
            }
        }

        window.clear();
        DrawMenu(window,background,MainTitle);
        window.display();
    }
}

/*
    Function: moveup()
    Description: moves the selection of the choices in the menu up
    */
void Menu:: moveup()
{
    if (selectedItem - 1 >= 0)
    {
        MainMenu[selectedItem].setFillColor(sf::Color::Black);
        selectedItem--;
        MainMenu[selectedItem].setFillColor(sf::Color::Red);
        std::cout << "moving up" << std::endl;
    }
}

/*
    Funciton: movedown();
    Description: moves the selection of the choices in the menu down
    */
void Menu::movedown()
{
    if (selectedItem + 1 < 3)
    {
        MainMenu[selectedItem].setFillColor(sf::Color::Black);
        selectedItem++;
        MainMenu[selectedItem].setFillColor(sf::Color::Red);
        std::cout << "moving down" << std::endl;
    }
}

/*
    Funciton: getpressedItem()
    Description: retunrs the index of the array that the selected choice is on
    */
int Menu::getpressedItem()
{
    return this->selectedItem;
}

/*
    Function:DrawMenu()
    Description: draws the full menu including the background
    */
void Menu::DrawMenu(sf::RenderWindow& window, sf::Sprite& background, sf::Text&MainTitle)
{
    window.draw(background);
    window.draw(MainTitle);

    for (int i = 0; i < 3; i++)
    {
        window.draw(MainMenu[i]);
    }
}

/*
    Function:PlayGame()
    Description: when the play choice is selected the play game fucntion is called to actually run the game
    */
void Menu:: PlayGame(sf::RenderWindow& window)
{
    sf::Sprite gamebackground;
    sf::Texture texture1;
    sf::Text winnerb, winnerh;
    sf::Font winner;
    int exit = 0;

    winner.loadFromFile("Brush King.otf");

    winnerb.setFont(winner);
    winnerh.setFont(winner);
    winnerb.setString("Butch Wins");
    winnerh.setString("Harry Wins");
    winnerb.setFillColor(sf::Color::Red);
    winnerh.setFillColor(sf::Color::Red);
    winnerb.setPosition(sf::Vector2f(470, 384));
    winnerh.setPosition(sf::Vector2f(470, 384));
    winnerb.setCharacterSize(60);
    winnerh.setCharacterSize(60);
  
    texture1.loadFromFile("Butch Fighter Baclground.png");
    gamebackground.setTexture(texture1);
    gamebackground.setScale(9, 4);
    
    Butch butch;
    Harry harry;

    HealthBar bHealth(sf::Vector2f(620, 40), sf::Vector2f(0, 0));
    HealthBar hHealth(sf::Vector2f(620, 40), sf::Vector2f(820, 0));

    


    while (exit != 1) {
        //check for attack damage, 
        if (butch.getPlayerAtkBox().getGlobalBounds().intersects(harry.getPlayerBox().getGlobalBounds()))
        {
            harry.damage(10);
            harry.pushBack(100, true);
        }
        if (harry.getPlayerAtkBox().getGlobalBounds().intersects(butch.getPlayerBox().getGlobalBounds()))
        {
            butch.damage(10);
            butch.pushBack(100, true);
        }

        bHealth.adjustSize(butch.getHP(), 100);
        hHealth.adjustSize(harry.getHP(), 100);


        //check if players are running into eachother

        while (butch.getPlayerBox().getGlobalBounds().intersects(harry.getPlayerBox().getGlobalBounds()))
        {
            butch.pushBack(1,true);
            harry.pushBack(1,true);
        }

        //ensure players always face eachother
        if (harry.getPlayerLoc().x > butch.getPlayerLoc().x) {
            butch.update(0.0, true);
            harry.update(0.0, false);
        }
        else {
            butch.update(0.0, false);
            harry.update(0.0, true);
        }

        

        window.draw(gamebackground);
        butch.draw(window);
        harry.draw(window);

        window.draw(hHealth.getBackBar());
        window.draw(bHealth.getBackBar());
        window.draw(hHealth);
        window.draw(bHealth);
       

        if (!butch.isAlive())
        {
            cout << "Butch has died" << endl;
            exit = 1;
            window.draw(winnerh);
        }
        if (!harry.isAlive())
        {
            cout << "Harry has died" << endl;
            exit = 1;
            window.draw(winnerb);
        }

        window.display();
        window.clear();
    }

    Sleep(3000);

    
}

/*
    Function: playMenuMusic()
    Description: loads the menu music into sound buffer and sets the buffer to the menu sound. sets loop to true and starts
    */
void Menu::playMenuMusic()
{
    if (this->menuSound.getStatus() != sf::Sound::Playing)
    {
    this->menuBuffer.loadFromFile("WSU_Fight_Song.wav");
    this->menuSound.setBuffer(this->menuBuffer);
    this->menuSound.setLoop(true);
    this->menuSound.play();
    }
}

/*
    Function: playMenuMusic()
    Description: stops the menu music
    */
void Menu::stopMenuMusic()
{
    this->menuSound.stop();
}