#include "Fighter.hpp"

class Butch : public Fighter {

public:
	Butch() : Fighter() {
		loadTextures();
		loadAtkSound("Punch.wav");
		//TODO set first texture to sprite
		this->_sprite.setPosition(sf::Vector2f(150, this->_groundLevel));

	}

	~Butch();

	void update(float time, bool facingRight);


private:

	void loadTextures();

};