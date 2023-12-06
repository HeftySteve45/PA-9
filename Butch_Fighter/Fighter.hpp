#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Fighter {

public:

	Fighter(const int HP = 100, const int maxJumpVel = 50, const bool facingRight = true);
	virtual ~Fighter()
	{

	}

	int getHP() const;//returns the current health of a fighter
	int getMaxHP() const;//retrns the maximum health a fighter can have
	bool isAlive() const;//reutrns true if the fighters health is > 0, else returns false
	sf::Vector2f getPlayerLoc() const;//get the (x,y) pos of the fighters sprite origin
	sf::Sprite getPlayerBox() const;//get the fighters hitbox
	sf::RectangleShape getPlayerAtkBox() const;//get the fighters attack hitbox
	void pushBack(float numberPixels);//pushes player back n number of pixels from the direction they are facing

	void damage(int damage);//takes health away, if the fighter is blocking, it will take away 50% of the total damage

	void update(bool facingRight);//updates players inputs and locations along with sprite animation
	void draw(sf::RenderWindow& window);//draws the fighter to the window

protected:

	//MOVEMENT
	void moveF();//forward
	void moveB();//backward

	//ACTIONS
	void punch();//shorter range attack, cannot be ducked under to miss damage
	void kick();//longer range attack, can be ducked under to miss all damage
	void block();//protects from 50% of damage of both a kick and a punch
	void jump();//allows player to jump to dodge attack or to switch the sides
	void duck();//allows the player to dodge a kick attack

	//UPDATES
	void updateGravity();//updates the gravity physics, should be called on each update
	void updateFacing(bool facingRight);//ensure players always face the same direction by flipping sprite
	virtual void updateInputs() = 0;//pure virtual since both butch and harry require different inputs

	//ASSET LOADING
	void loadTextures(const string& fileName);//loads textures by using sf::IntRect to cut sprite frames out of a single sheet
	void loadAtkSound(const string& fileName);//loads the attack sound into memory

	int _HP;
	int _maxHP;
	int _curJumpVel;
	int _maxJumpVel;
	int _groundLevel;
	bool _facingRight;
	bool _inAir;
	bool _inAction;
	bool _isBlocking;
	bool _defending;

	sf::Sprite _sprite;//a rectangle that can display an image
	sf::Texture _Texture;//loads the entire sprite sheet
	sf::IntRect _animation[9];//holds rectangle information for sprites out of our single sprite sheet
	sf::SoundBuffer _atkSoundBuf;
	sf::Sound _atkSound;
	sf::RectangleShape _atkHitbox;//if this colides with the global bounds of another fighter, the fighter takes damage
};