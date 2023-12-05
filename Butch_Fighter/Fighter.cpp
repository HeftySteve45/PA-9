#include "Fighter.hpp"

Fighter::Fighter(const int HP, const int maxJumpVel, const bool facingRight)
{
	this->_HP = HP;
	this->_maxJumpVel = maxJumpVel;
	this->_curJumpVel = 0;
	this->_groundLevel = 550;
	this->_facingRight = facingRight;
	this->_inAction = this->_inAir = this->_isBlocking = this->_moved = false;
	this->_attacking = this->_defending = false;
	this->cooldown = 0;
	//box always exists, just out of the bounds so players do not collide with it accidentally 
	this->_atkHitbox.setSize(sf::Vector2f(75, 75));
	this->_atkHitbox.setPosition(sf::Vector2f(-300, -300));
	this->_atkHitbox.setFillColor(sf::Color(255, 255, 255, 255));
}

Fighter::~Fighter()
{

}

int Fighter::getHP() const
{
	return this->_HP;
}

bool Fighter::isAlive() const
{
	if (this->_HP == 0)
	{
		return false;
	}
	return true;
}

sf::Vector2f Fighter::getPlayerLoc() const
{
	return this->_sprite.getPosition();
}

sf::Sprite Fighter::getPlayerBox() const
{
	return this->_sprite;
}

sf::RectangleShape Fighter::getPlayerAtkBox() const
{
	return this->_atkHitbox;
}

void Fighter::pushBack(float numberPixels, bool override)
{

	if (this->_moved || override) {
		if (this->_facingRight)
		{
			this->_sprite.move(sf::Vector2f(-numberPixels, 0));
		}
		else if (!this->_facingRight)
		{
			this->_sprite.move(sf::Vector2f(numberPixels, 0));
		}
	}

}

void Fighter::damage(int damage)
{
	if (this->_isBlocking)
	{
		this->_HP -= (damage / 2);
	}
	else
	{
		this->_HP -= damage;
	}
}

void Fighter::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
	window.draw(this->_atkHitbox);
}

void Fighter::moveB()
{
	if (!this->_inAction) {
		if (this->_facingRight)
		{
			this->_sprite.setTextureRect(this->_Animation[2]);
		}
		else
		{
			this->_sprite.setTextureRect(this->_Animation[1]);
		}


		if (this->_sprite.getPosition().x != 0)
		{
			this->_sprite.move(sf::Vector2f(-10, 0));
		}
	}
}

void Fighter::moveF()
{
	if (!this->_inAction) {
		if (this->_facingRight)
		{
			this->_sprite.setTextureRect(this->_Animation[1]);
		}
		else
		{
			this->_sprite.setTextureRect(this->_Animation[2]);
		}

		this->_sprite.setTextureRect(this->_Animation[1]);
		if (this->_sprite.getPosition().x != 1440)
		{
			this->_sprite.move(sf::Vector2f(10, 0));
		}
	}
}

void Fighter::jump()
{
	if (!this->_inAction && !this->_inAir)//on the ground
	{
		this->_curJumpVel = this->_maxJumpVel;
	}
}

void Fighter::duck()
{
	if (!this->_inAir && !this->_inAction)
	{
		this->_sprite.setTextureRect(this->_Animation[7]);
		this->_sprite.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y + 80);
	}
}

void Fighter::punch()
{
	this->_sprite.setTextureRect(this->_Animation[5]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_atkSound.play();//TODO move this to punch and kick in Fighter.cpp when they are made
		if (this->_facingRight)
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x + 100, this->_sprite.getPosition().y));
		}
		else
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x - 175, this->_sprite.getPosition().y));
		}
	}

}

void Fighter::kick()
{
	this->_sprite.setTextureRect(this->_Animation[6]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_atkSound.play();//TODO move this to punch and kick in Fighter.cpp when they are made
		if (this->_facingRight)
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x + 175, this->_sprite.getPosition().y));
		}
		else
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x - 250, this->_sprite.getPosition().y));
		}
	}
}

void Fighter::block()
{
	this->_sprite.setTextureRect(this->_Animation[4]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_isBlocking = true;
		//TODO play block animation, each animation 
		//should be the same number of frames so we can 
		//have a static var keep track of how many frames passed
	}
}

void Fighter::updateGravity()//updates the gravity physics, should be called on each update after inputs are detected
{
	if (this->_sprite.getPosition().y < this->_groundLevel) {
		this->_inAir = true;
		this->_moved = true;
		this->_curJumpVel -= sqrt(this->_curJumpVel) / 5;//curv the velocity so it is fast and slows down as the player gets higher
	}
	else
	{
		this->_inAir = false;
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
	if (!facingRight)//sprite needs to be flipped
		//SHOULDNT face right and we ARE facing right, flip sprite
	{
		this->_sprite.setScale(sf::Vector2f(-4, 4));
		this->_facingRight = false;
	}
	else if (facingRight)
		//SHOULD face right and we ARENT facing right, flip sprite
	{
		this->_sprite.setScale(sf::Vector2f(4, 4));
		this->_facingRight = true;
	}
}

void Fighter::loadAtkSound(const string& fileName)
{
	this->_atkSoundBuf.loadFromFile(fileName);
	this->_atkSound.setBuffer(this->_atkSoundBuf);
}