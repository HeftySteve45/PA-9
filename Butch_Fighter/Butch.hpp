#include "Fighter.hpp"

class Butch : public Fighter {

public:

	Butch() : Fighter() {
		loadTextures("Butch_Sprites.png");
		loadAtkSound("Punch.wav");
		this->_sprite.setPosition(sf::Vector2f(150, this->_groundLevel));//start on left side of window

	}
	~Butch();

private:

	void updateInputs();

};