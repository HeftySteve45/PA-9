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
	~Fighter();

	//getters
	int getHP() const;
	bool isAlive() const;
	sf::Vector2f getPlayerLoc() const;
	sf::Sprite getPlayerBox() const;
	sf::RectangleShape getPlayerAtkBox() const;
	void pushBack(float numberPixels, bool override = false);//pushes player back n number of pixels from the direction they are facing

	void damage(int damage);

	virtual void update(float time, bool facingRight) = 0;//pure virtual, Butch and Harry have different key inputs to check check for
	void draw(sf::RenderWindow& window);

	virtual void loadTextures() = 0;

protected:

	//MOVEMENT
	void moveF();
	void moveB();
	void jump();
	void duck();

	//ACTIONS
	void punch();
	void kick();
	void block();

	void updateGravity();//updates the gravity physics, should be called on each update
	void updateFacing(bool facingRight);
	void loadAtkSound(const string& fileName);

	int _HP;
	int _curJumpVel;
	int _maxJumpVel;
	int _groundLevel;
	bool _facingRight;
	bool _inAir;
	bool _inAction;
	bool _isBlocking;
	bool _moved;
	bool _attacking;
	bool _defending;
	int cooldown; //counts frames, each attack is 0.55 seconds so it should max at 33 frames of cooldown

	sf::Sprite _sprite;
	sf::Texture _Texture;
	sf::IntRect _Animation[9];
	sf::SoundBuffer _atkSoundBuf;
	sf::Sound _atkSound;
	sf::RectangleShape _atkHitbox;//if this colides with the global bounds of another fighter, the fighter takes damage
	sf::Clock clock;
};