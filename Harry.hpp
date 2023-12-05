#include "Fighter.hpp"

class Harry : public Fighter {

public:
	Harry() : Fighter() {
		loadTextures();
		loadAtkSound("Punch.wav");
		this->_sprite.setPosition(sf::Vector2f(1290, this->_groundLevel));
	}

	~Harry();

	void update(float time, bool facingRight);


private:

	void loadTextures();

};