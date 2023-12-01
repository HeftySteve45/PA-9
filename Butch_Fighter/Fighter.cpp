#include "Fighter.hpp"

Fighter::Fighter(const int HP, const int maxJumpVel, const bool facingRight)
{
	this->_HP = HP;
	this->_maxJumpVel = maxJumpVel;
	this->_curJumpVel = 0;
	this->_pTexture = nullptr;
	this->_groundLevel = 475;
	this->_facingRight = facingRight;
}

Fighter::~Fighter()
{
	if (this->_pTexture != nullptr)
	{
		delete this->_pTexture;
	}
}

int Fighter::getHP() const
{
	return this->_HP;
}

sf::Vector2f Fighter::getPlayerLoc() const
{
	return this->_sprite.getPosition();
}

void Fighter::setHP(int newHP)
{
	this->_HP = newHP;
}

void Fighter::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
}

void Fighter::moveL()
{
	this->_sprite.move(sf::Vector2f(-10, 0));
}

void Fighter::moveR()
{
	this->_sprite.move(sf::Vector2f(10, 0));
}

void Fighter::jump()
{
	if (this->_sprite.getPosition().y == this->_groundLevel)//on the ground
	{
		this->_curJumpVel = this->_maxJumpVel;
	}
}

void Fighter::duck()
{
	if (this->_sprite.getPosition().y == this->_groundLevel)//on the ground
	{

	}
}

//void Fighter::punch()
//{
//
//}
//
//void Fighter::kick()
//{
//
//}

void Fighter::updateGravity()//updates the gravity physics, should be called on each update after inputs are detected
{
	if (this->_curJumpVel > 0) {
		this->_curJumpVel -= sqrt(this->_curJumpVel) / 5;//curv the velocity so it is fast and slows down as the player gets higher
	}

	if (this->_sprite.getPosition().y > this->_groundLevel)//under the floor, move them back to on the floor
	{
		this->_sprite.setPosition(sf::Vector2f(this->_sprite.getPosition().x, this->_groundLevel));
	}
	else if (this->_sprite.getPosition().y < this->_groundLevel)//player is in the air, gravity should move them down
	{
		this->_sprite.move(sf::Vector2f(0, 15));
	}
	
	this->_sprite.move(sf::Vector2f(0, -this->_curJumpVel));
}

void Fighter::updateFacing(bool facingRight)
{
	if (!facingRight && this->_facingRight)//sprite needs to be flipped
		//SHOULDNT face right and we ARE facing right, flip sprite
	{
		this->_sprite.setScale(sf::Vector2f(-0.25, 0.25));//TODO ensure scale is correct, first should be - to face left
	}
	else if (facingRight && !this->_facingRight)
		//SHOULD face right and we ARENT facing right, flip sprite
	{
		this->_sprite.setScale(sf::Vector2f(0.25, 0.25));//TODO ensure scale is correct, first should be + to face left
	}
}

void Fighter::loadAtkSound(const string& fileName)
{
	this->atkSoundBuf.loadFromFile(fileName);
	this->atkSound.setBuffer(this->atkSoundBuf);
}