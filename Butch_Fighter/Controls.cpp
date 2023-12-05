#include "Controls.h"

/*
Function: Controls()
Description: sets all of the words to the right words colors and positions and loads the font and the sprite
*/
Controls::Controls()
{
	sf::Texture t1;

	//loading the font and sprite
	Tfont.loadFromFile("Martyric_PersonalUse.ttf");
	title_name.setFont(Tfont);
	title_name.setString("Controls");
	title_name.setFillColor(sf::Color::Red);
	title_name.setOutlineColor(sf::Color::Black);
	title_name.setOutlineThickness(3);
	title_name.setCharacterSize(120);
	title_name.setPosition(450, 0);

	// Action word
	font.loadFromFile("Brush King.otf");

	Titles[0].setFont(font);
	Titles[0].setString("Movement");
	Titles[0].setPosition(100, 175);
	Titles[0].setFillColor(sf::Color::Red);

	//Butch 
	Titles[1].setFont(font);
	Titles[1].setString("Butch");
	Titles[1].setPosition(580, 175);
	Titles[1].setFillColor(sf::Color::Red);


	//Harry
	Titles[2].setFont(font);
	Titles[2].setString("Harry");
	Titles[2].setPosition(1060, 175);
	Titles[2].setFillColor(sf::Color::Red);


	//Movements 
	controls[0].setFont(font);
	controls[0].setString("Right");
	controls[0].setFillColor(sf::Color::Black);
	controls[0].setPosition(100, 250);

	controls[1].setFont(font);
	controls[1].setString("Left");
	controls[1].setFillColor(sf::Color::Black);
	controls[1].setPosition(100, 325);

	controls[2].setFont(font);
	controls[2].setString("Jump");
	controls[2].setFillColor(sf::Color::Black);
	controls[2].setPosition(100, 400);

	controls[3].setFont(font);
	controls[3].setString("Duck");
	controls[3].setFillColor(sf::Color::Black);
	controls[3].setPosition(100, 475);

	controls[4].setFont(font);
	controls[4].setString("Punch");
	controls[4].setFillColor(sf::Color::Black);
	controls[4].setPosition(100, 550);

	controls[5].setFont(font);
	controls[5].setString("Kick");
	controls[5].setFillColor(sf::Color::Black);
	controls[5].setPosition(100, 625);

	controls[6].setFont(font);
	controls[6].setString("Block");
	controls[6].setFillColor(sf::Color::Black);
	controls[6].setPosition(100, 700);

	back_s.setSize(sf::Vector2f(150, 80));
	back_s.setFillColor(sf::Color::Red);
	back_s.setPosition(10, 10);
	back_s.setOutlineColor(sf::Color::Black);
	back_s.setOutlineThickness(3);

	back.setFont(font);
	back.setString("Back");
	back.setFillColor(sf::Color::White);
	back.setPosition(25,30);
}

/*
Function: ~Controls()
Description: The descturctor for the Controls class
*/
Controls:: ~Controls()
{

}

/*
	Function: ControlScreen()
	Description: runs the control sceen menu
	*/
void Controls::ControlScreen(sf::RenderWindow& window)
{
	DrawControls(window);
}

/*
	Function: DrawControls
	Desciption: draws the control screen
	*/
void Controls::DrawControls(sf::RenderWindow& window)
{
	sf::Sprite background;
	sf::Texture t1, t2;
	sf::Event event;
	t1.loadFromFile("Butch c.png");
	background.setTexture(t1);
	background.setScale(9, 4);

	t2.loadFromFile("Keyboard.png");

	int exit = 0;

	while (exit == 0)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Return:
					window.clear();
					exit = 1;
					break;
				}
			}
		}
		// right
		P1[0].setTexture(t2);
		P1[0].setTextureRect(sf::IntRect(214, 128, 30, 30));
		P1[0].setPosition(620, 225);
		P1[0].setScale(2, 2);

		P2[0].setTexture(t2);
		P2[0].setTextureRect(sf::IntRect(663, 192, 30, 30));
		P2[0].setPosition(1100, 225);
		P2[0].setScale(2, 2);

		//left
		P1[1].setTexture(t2);
		P1[1].setTextureRect(sf::IntRect(150, 128, 30, 30));
		P1[1].setPosition(620, 300);
		P1[1].setScale(2, 2);

		P2[1].setTexture(t2);
		P2[1].setTextureRect(sf::IntRect(598, 192, 30, 30));
		P2[1].setPosition(1100, 300);
		P2[1].setScale(2, 2);

		//jump
		P1[2].setTexture(t2);
		P1[2].setTextureRect(sf::IntRect(184, 96, 30, 30));
		P1[2].setPosition(620, 375);
		P1[2].setScale(2, 2);

		P2[2].setTexture(t2);
		P2[2].setTextureRect(sf::IntRect(631, 159, 30, 30));
		P2[2].setPosition(1100, 375);
		P2[2].setScale(2, 2);

		//duck
		P1[3].setTexture(t2);
		P1[3].setTextureRect(sf::IntRect(184, 129, 30, 30));
		P1[3].setPosition(620, 450);
		P1[3].setScale(2, 2);

		P2[3].setTexture(t2);
		P2[3].setTextureRect(sf::IntRect(631, 192, 30, 30));
		P2[3].setPosition(1100, 450);
		P2[3].setScale(2, 2);

		//punch 
		P1[4].setTexture(t2);
		P1[4].setTextureRect(sf::IntRect(150, 96, 30, 30));
		P1[4].setPosition(620, 525);
		P1[4].setScale(2, 2);

		P2[4].setTexture(t2);
		P2[4].setTextureRect(sf::IntRect(390, 160, 30, 30));
		P2[4].setPosition(1100, 525);
		P2[4].setScale(2, 2);

		//kick
		P1[5].setTexture(t2);
		P1[5].setTextureRect(sf::IntRect(214, 96, 30, 30));
		P1[5].setPosition(620, 600);
		P1[5].setScale(2, 2);

		P2[5].setTexture(t2);
		P2[5].setTextureRect(sf::IntRect(422, 160, 30, 30));
		P2[5].setPosition(1100, 600);
		P2[5].setScale(2, 2);

		//block
		P1[6].setTexture(t2);
		P1[6].setTextureRect(sf::IntRect(246, 96, 30, 30));
		P1[6].setPosition(620, 675);
		P1[6].setScale(2, 2);

		P2[6].setTexture(t2);
		P2[6].setTextureRect(sf::IntRect(455, 160, 30, 30));
		P2[6].setPosition(1100, 675);
		P2[6].setScale(2, 2);


		window.draw(background);
		window.draw(title_name);
		window.draw(back_s);
		window.draw(back);
		DrawArrays(window);
		window.display();
	}
}

/*
	Function: DrawArrays()
	Description: Draws the text arrays
	*/
void Controls::DrawArrays(sf::RenderWindow& window)
{

	for (int i = 0; i < 3; ++i)
	{
		window.draw(Titles[i]);
	}
	for (int j = 0; j < 7; ++j)
	{
		window.draw(controls[j]);
		window.draw(P1[j]);
		window.draw(P2[j]);
	}
}