
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

class Controls
{
public:
	/*
	Function: Controls()
	Description: sets all of the words to the right words colors and positions and loads the font and the sprite
	*/
	Controls();

	/*
	Function: ~Controls()
	Description: The descturctor for the Controls class
	*/
	~Controls();

	/*
	Function: ControlScreen()
	Description: runs the control sceen menu
	*/
	void ControlScreen(sf::RenderWindow& window);

	/*
	Function: DrawControls
	Desciption: draws the control screen
	*/
	void DrawControls(sf::RenderWindow& window);

	/*
	Function: DrawArrays()
	Description: Draws the text arrays
	*/
	void DrawArrays(sf::RenderWindow& window);
private:
	sf::Text controls[7];
	sf::Sprite P1[7];
	sf::Sprite P2[7];
	sf::Font font, Tfont;
	sf::Text Titles[3];
	sf::Text title_name;
	sf::Text back;
	sf::RectangleShape back_s;
};