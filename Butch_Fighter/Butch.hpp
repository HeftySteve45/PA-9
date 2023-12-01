#include "Fighter.hpp"

class Butch : public Fighter {

public:
	Butch() : Fighter() {
		//TODO loadTextures();
		loadAtkSound("Punch.wav");
		//TODO set first texture to sprite


	}

	~Butch();

	void update(float time, bool facingRight);


private:

	void loadTextures();

};