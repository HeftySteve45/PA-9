#pragma once
#include <SFML/Graphics.hpp>


class Menu
{
public:
	// Menu(double width, double height);
	void displayMenu();
	//~Menu();
	void displayMenu();

private:
	sf::Font title;
	sf::Font choices;
};
