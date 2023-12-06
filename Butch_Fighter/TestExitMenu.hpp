#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ExitMenu.h"

using std::cout;

void TestExitMenu()
{
	sf::RenderWindow window(sf::VideoMode(1440, 760), "ExitMenu Test");

	ExitMenu menu;

	cout << "Displaying Exit Menu\n";
	menu.displayExitMenu(window);
}