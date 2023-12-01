#include "Fighter.hpp"

class Harry : public Fighter {

public:
	Harry() : Fighter() {
		this->_facingRight = false; //start on right so face left
		//TODO loadTextures();
		loadAtkSound("Punch.wav");
		//TODO set first texture to sprite


	}

	~Harry();

	void update(float time, bool facingRight);


private:

	void loadTextures();

};