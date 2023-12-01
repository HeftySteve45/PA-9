#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>

class ExitMenu
{
public:
	/*
	Function: ExitMenu()
	Description: it sets all of the shapes and words to the right colors, size, and font
	*/
	ExitMenu();

	/*
	Fucntion: ~ExitMenu()
	Description: the destructor for the  ExitMenu class
	*/
	~ExitMenu();

	/*
	Function: displayExitMenu()
	Description: displays the exit menu
	*/
	void displayExitMenu(sf::RenderWindow& window);

	/*
	Funciton: drawChoices();
	Description: draws the title and the choices for the exit menu
	*/
	void drawChoices(sf::RenderWindow& window);

	/*
	Function: moveright();
	Description: moves your choice to the right
	*/
	void moveRight();

	/*
	Function: moveleft();
	Description: moves your choice to the left
	*/
	void moveleft();

	/*
	Function GetBoxNumber
	Description: gets the number of the box that it is currently on;
	*/
	int GetBoxNumber();
private:
	sf::RectangleShape exit_menu;
	sf::RectangleShape boxes[2];
	sf::Text words[3];
	sf::Font font;
	int boxnumber;
};