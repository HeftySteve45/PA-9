#pragma once
#include <iostream>
#include <windows.h>
#include "SFML/Graphics.hpp"
#include "HealthBar.hpp"

using std::cout;

void TestHealthBar(void)
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "HealthBar Test");

	HealthBar TestBar(sf::Vector2f(350, 200), sf::Vector2f(0, 0));
	int maxHealth = 100, currentHealth = 100;

	cout << "Drawing HealthBar\n";
	
	window.clear();
	window.draw(TestBar.getBackBar());
	window.draw(TestBar);
	window.display();
	Sleep(1000);

	cout << "Damaging HealthBar -20% \n";

	for (int i = 0; i < 5; i++)
	{
		currentHealth -= 20;
		cout << "Damaging HealthBar -20% \n";
		TestBar.adjustSize(currentHealth, maxHealth);
		window.clear();
		window.draw(TestBar.getBackBar());
		window.draw(TestBar);
		window.display();
		Sleep(1000);
	}

}