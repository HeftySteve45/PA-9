#include "Butch.hpp"

Butch::~Butch()
{

}

void Butch::update(float time, bool facingRight)
{
	this->_moved = false;
	this->cooldown--;
	updateGravity();

	if (this->_atkHitbox.getPosition().x != -75)//return attack box away from screen
	{
		this->_atkHitbox.setSize(sf::Vector2f(20, 75));
		this->_atkHitbox.setPosition(sf::Vector2f(-75, -75));
	}

	if (!this->_inAction)
	{
		this->_sprite.setTextureRect(this->_Animation[0]);
		this->_sprite.setOrigin(sf::Vector2f(20, 35));
	}

	if (this->_atkSound.getStatus() != sf::Sound::Playing)
	{
		this->_inAction = false;
	}
	else
	{
		this->_inAction = true;
	}

	if (!this->_defending) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->moveB();
			this->_moved = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->moveF();
			this->_moved = true;
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

	if (this->_inAir)
	{
		this->_sprite.setTextureRect(this->_Animation[3]);
	}

	if (!this->isAlive())
	{
		this->_sprite.setTextureRect(this->_Animation[8]);
		this->_sprite.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y + 180);
	}

	if (this->_sprite.getPosition().x < 0)
	{
		this->_sprite.setPosition(sf::Vector2f(0, this->_sprite.getPosition().y));
	}
	if (this->_sprite.getPosition().x > 1440)
	{
		this->_sprite.setPosition(sf::Vector2f(1440, this->_sprite.getPosition().y));
	}

	updateFacing(facingRight);
}

void Butch::loadTextures()
{
	this->_Texture.loadFromFile("Butch_Sprites.png");
	this->_sprite.setTexture(this->_Texture);

	this->_Animation[0] = sf::IntRect(40, 0, 38, 70);//base frame
	this->_Animation[1] = sf::IntRect(78, 0, 42, 70);//walk forward
	this->_Animation[2] = sf::IntRect(119, 0, 33, 70);//walk backward
	this->_Animation[3] = sf::IntRect(173, 73, 54, 56);//jump
	this->_Animation[4] = sf::IntRect(153, 0, 39, 70);//block
	this->_Animation[5] = sf::IntRect(258, 189, 60, 70);//punch
	this->_Animation[6] = sf::IntRect(179, 186, 80, 67);//kick
	this->_Animation[7] = sf::IntRect(0, 69, 36, 50);//duck
	this->_Animation[8] = sf::IntRect(77, 259, 89, 21);//death


}

