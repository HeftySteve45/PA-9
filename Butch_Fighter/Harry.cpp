#include "Harry.hpp"

Harry::~Harry()
{

}

void Harry::updateInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->moveB();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->moveF();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->jump();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
		{
			this->punch();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
		{
			this->kick();
		}
	}
}
