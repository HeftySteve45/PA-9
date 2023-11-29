#pragma once
#include <SFML/Graphics.hpp>


class Menu
{
public:
	Menu();
	~Menu();
	void displayMenu();
	
private:
	sf::Font title;
	sf::Font choices;
	sf::Text MainMenu[3];
	int selectedItem;
};
