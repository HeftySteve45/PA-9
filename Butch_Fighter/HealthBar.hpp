#pragma once
#include "SFML/Graphics.hpp"


/*
HealthBar takes in two sf::Vector2f, the first is size of the healthbar, and the second is the position of the health bar.
To update the health bar and show damage, you need to call the adjustSize function which takes two float values. the first is the current health value of the player and the second is the maximum health of the player.	
	when the health bar/s is drawn by the window it will then show its updated size.

currently the backbar(red part of the healthbar) and the healthbar itself need two seperate draw calls to display properly. you must draw the backbar before the Healthbar to display them properly. 
*/

class HealthBar :public sf::RectangleShape
{
public:
	HealthBar(const sf::Vector2f& size, const sf::Vector2f& pos) : RectangleShape(size)
	{
		
		mBackBar.setSize(size);
		mBackBar.setFillColor(sf::Color::Red);
		this->setPosition(pos);
		this->setFillColor(sf::Color::Yellow);
	}
	
	void adjustSize(float healthValue, float maxHealth);
	
	sf::RectangleShape& getBackBar();

private:
	sf::RectangleShape mBackBar;
	
};