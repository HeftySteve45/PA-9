#pragma once
#include "SFML/Graphics.hpp"


/*
HealthBar takes in two sf::Vector2f, the first is size of the healthbar, and the second is the position of the health bar.
To update the health bar and show damage, you need to call the adjustSize function which takes two float values. the first is the current health value of the player and the second is the maximum health of the player.	
	when the health bar/s is drawn by the window it will then show its updated size.

*/

class HealthBar :public sf::RectangleShape
{
public:
	HealthBar(const sf::Vector2f& size, const sf::Vector2f& pos) : RectangleShape(size)
	{
		
		mBackBar.setSize(size);
		mBackBar.setFillColor(sf::Color(166, 15, 45));
		this->mBackBar.setPosition(pos);
		this->setPosition(pos);
		this->setFillColor(sf::Color(255, 198, 39));
	}
	
	void adjustSize(float healthValue, float maxHealth);
	void draw(sf::RenderWindow& window);

	sf::RectangleShape& getBackBar();

private:
	sf::RectangleShape mBackBar;
	
};