#include "Butch.hpp"

Butch::~Butch()
{

}

void Butch::updateInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->duck();
		}
		else
		{
			this->block();
		}

		this->_defending = true;
	}
	else {
		this->_defending = false;
	}

	if (!this->_defending) {//defensive action so fighter cannot move
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->moveB();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->moveF();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->jump();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			this->punch();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			this->kick();
		}
	}
}

