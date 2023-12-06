#include "Fighter.hpp"

Fighter::Fighter(const int HP, const int maxJumpVel, const bool facingRight)
{
	this->_HP = this->_maxHP = HP;
	this->_maxJumpVel = maxJumpVel;
	this->_curJumpVel = 0;
	this->_groundLevel = 600;
	this->_facingRight = facingRight;
	this->_inAction = this->_inAir = this->_isBlocking = this->_defending = false;

	//box always exists, just out of the bounds so players do not collide with it accidentally 
	this->_atkHitbox.setSize(sf::Vector2f(25, 25));
	this->_atkHitbox.setPosition(sf::Vector2f(-300, -300));
}

int Fighter::getHP() const
{
	return this->_HP;
}

int Fighter::getMaxHP() const
{
	return this->_maxHP;
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

void Fighter::pushBack(float numberPixels)
{
	if (this->_facingRight)
	{
		this->_sprite.move(sf::Vector2f(-numberPixels, 0));
	}
	else if (!this->_facingRight)
	{
		this->_sprite.move(sf::Vector2f(numberPixels, 0));
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

void Fighter::update(bool facingRight)
{
	updateGravity();

	this->_isBlocking = false;

	this->_atkHitbox.setPosition(sf::Vector2f(-300, -300));//set so players cannot hit them accidentally

	this->_sprite.setTextureRect(this->_animation[0]);
	this->_sprite.setOrigin(sf::Vector2f(20, 35));

	if (this->_atkSound.getStatus() != sf::Sound::Playing)
	{
		this->_inAction = false;
	}
	else
	{
		this->_inAction = true;
	}

	updateInputs();

	if (this->_inAir)
	{
		this->_sprite.setTextureRect(this->_animation[3]);
	}

	if (!this->isAlive())
	{
		this->_sprite.setTextureRect(this->_animation[8]);
		this->_sprite.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y + 180);
	}

	if (this->_sprite.getPosition().x < 75)
	{
		this->_sprite.setPosition(sf::Vector2f(75, this->_sprite.getPosition().y));
	}
	if (this->_sprite.getPosition().x > 1365)
	{
		this->_sprite.setPosition(sf::Vector2f(1365, this->_sprite.getPosition().y));
	}

	updateFacing(facingRight);
}

void Fighter::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
}

void Fighter::moveB()
{
	if (!this->_inAction) {
		if (this->_facingRight)
		{
			this->_sprite.setTextureRect(this->_animation[2]);
		}
		else
		{
			this->_sprite.setTextureRect(this->_animation[1]);
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
			this->_sprite.setTextureRect(this->_animation[1]);
		}										
		else									
		{										
			this->_sprite.setTextureRect(this->_animation[2]);
		}

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
		this->_sprite.setTextureRect(this->_animation[7]);
		this->_sprite.setPosition(this->_sprite.getPosition().x, this->_sprite.getPosition().y + 80);
	}
}

void Fighter::punch()
{
	this->_sprite.setTextureRect(this->_animation[5]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_atkSound.play();
		if (this->_facingRight)
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x + 160, this->_sprite.getPosition().y - 75));
		}
		else
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x - 175, this->_sprite.getPosition().y - 75));
		}
	}

}

void Fighter::kick()
{
	this->_sprite.setTextureRect(this->_animation[6]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_atkSound.play();
		if (this->_facingRight)
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x + 245, this->_sprite.getPosition().y - 150));
		}
		else
		{
			this->_atkHitbox.setPosition(sf::Vector2f(this->_sprite.getPosition().x - 250, this->_sprite.getPosition().y - 150));
		}
	}
}

void Fighter::block()
{
	this->_sprite.setTextureRect(this->_animation[4]);
	if (!this->_inAction && !this->_inAir)
	{
		this->_isBlocking = true;
	}
}

void Fighter::updateGravity()//updates the gravity physics, should be called on each update after inputs are detected
{
	if (this->_sprite.getPosition().y < this->_groundLevel) {
		this->_inAir = true;
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
	if (!facingRight)
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

void Fighter::loadTextures(const string& fileName)
{
	this->_Texture.loadFromFile(fileName);
	this->_sprite.setTexture(this->_Texture);
	this->_animation[0] = sf::IntRect(40, 0, 38, 70);//base frame
	this->_animation[1] = sf::IntRect(78, 0, 42, 70);//walk forward
	this->_animation[2] = sf::IntRect(119, 0, 33, 70);//walk backward
	this->_animation[3] = sf::IntRect(173, 73, 54, 56);//jump
	this->_animation[4] = sf::IntRect(153, 0, 39, 70);//block
	this->_animation[5] = sf::IntRect(258, 189, 60, 70);//punch
	this->_animation[6] = sf::IntRect(179, 186, 79, 67);//kick
	this->_animation[7] = sf::IntRect(0, 69, 36, 50);//duck
	this->_animation[8] = sf::IntRect(77, 259, 89, 21);//death
}

void Fighter::loadAtkSound(const string& fileName)
{
	this->_atkSoundBuf.loadFromFile(fileName);
	this->_atkSound.setBuffer(this->_atkSoundBuf);
}
