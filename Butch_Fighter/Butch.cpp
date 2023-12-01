#include "Butch.hpp"

Butch::~Butch()
{

}

void Butch::update(float time, bool facingRight)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveL();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveR();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		duck();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		jump();
	}

	//TODO ADD KICK AND PUNCH ACTION KEYS
	//when punch or kick are called, activate play sound
	
	//TODO SET TEXTURE TO SPRITE BASED ON ACTION

	updateGravity();
	updateFacing(facingRight);
}

void Butch::loadTextures()
{

}
