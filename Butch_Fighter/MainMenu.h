#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu
{
public:
	// Menu(double width, double height);
	void displayMenu();
	//~Menu();
	//void displayMenu();
	void playMenuMusic();
	void stopMenuMusic();

private:
	sf::Font title;
	sf::Font choices;

	sf::Sound menuSound;
	sf::SoundBuffer menuBuffer;
};
