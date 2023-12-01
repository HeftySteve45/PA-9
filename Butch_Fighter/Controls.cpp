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
	t1.loadFromFile("Butch c.png");
	background.setTexture(t1);
	background.setScale(9, 4);

	t2.loadFromFile("Keyboard.png");

	window.draw(background);
	window.draw(title_name);
	DrawArrays(window);
	window.display();
	Sleep(3000);
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
	}

}