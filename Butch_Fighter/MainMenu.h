#pragma once
#include "ExitMenu.h"
#include "Controls.h"
#include "Butch.hpp"
#include "Harry.hpp"
#include "HealthBar.hpp"




class Menu
{
public:
	/*
	Function: Menu()
	Description: is the default constructor and sets the array up with the buttons for the main menu selection
	*/
	Menu();

	/*
	Funciton: ~Menu()
	Description: the default constructor for the main menu so it closes the window 
	*/
	~Menu();

	/*
	Function: displayMenu()
	Description: it displays the menu with the background and the choices
	*/
	void displayMenu();

	/*
	Function: moveup()
	Description: moves the selection of the choices in the menu up
	*/
	void moveup();

	/*
	Funciton: movedown();
	Description: moves the selection of the choices in the menu down
	*/
	void movedown();

	/*
	Funciton: getpressedItem()
	Description: retunrs the index of the array that the selected choice is on 
	*/
	int getpressedItem();

	/*
	Function:DrawMenu()
	Description: draws the full menu including the background
	*/
	void DrawMenu(sf::RenderWindow &window, sf::Sprite& background, sf::Text& MainTitle);

	/*
	Function:PlayGame()
	Description: when the play choice is selected the play game fucntion is called to actually run the game
	*/
	void PlayGame(sf::RenderWindow& window);
	
	/*
	Function: playMenuMusic()
	Description: loads the menu music into sound buffer and sets the buffer to the menu sound. sets loop to true and starts
	*/
	void playMenuMusic();

	/*
	Function: playMenuMusic()
	Description: stops the menu music
	*/
	void stopMenuMusic();

private:

	sf::Font title;
	sf::Font choices;
	sf::Text MainMenu[3];
	int selectedItem;
	ExitMenu exit;
	Controls controls;

	sf::Sound menuSound;
	sf::SoundBuffer menuBuffer;
};
