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

	Fighter(const int HP = 100, const int maxJumpVel = 40, const bool facingRight = true);
	~Fighter();

	//getters
	int getHP() const;
	sf::Vector2f getPlayerLoc() const;

	void setHP(int newHP);

	virtual void update(float time, bool facingRight) = 0;//pure virtual, Butch and Harry have different key inputs to check check for
	void draw(sf::RenderWindow& window);

	virtual void loadTextures() = 0;

protected:

	void moveL();
	void moveR();
	void jump();
	void duck();
	//void punch();
	//void kick();

	void updateGravity();//updates the gravity physics, should be called on each update
	void updateFacing(bool facingRight);
	void loadAtkSound(const string& fileName);

	int _HP;
	int _curJumpVel;
	int _maxJumpVel;
	int _groundLevel;
	bool _facingRight;
	sf::Sprite _sprite;
	sf::Texture* _pTexture;
	sf::SoundBuffer atkSoundBuf;
	sf::Sound atkSound;
};