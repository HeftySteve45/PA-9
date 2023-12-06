#include "Fighter.hpp"

class Harry : public Fighter {

public:

	Harry() : Fighter() {
		loadTextures("Harry_Sprites.png");
		loadAtkSound("Punch.wav");
		this->_sprite.setPosition(sf::Vector2f(1290, this->_groundLevel));//start on right side of window
	}

	~Harry();

private:

	void updateInputs();

};