#pragma once
#include <SFML/Graphics.hpp>


class Menu
{
public:
	Menu();
	~Menu();
	void displayMenu();
	void playMenuMusic();
	void stopMenuMusic();
	
private:
	sf::Font title;
	sf::Font choices;
	sf::Text MainMenu[3];
	int selectedItem;

	sf::Sound menuSound;
	sf::SoundBuffer menuBuffer;
};
