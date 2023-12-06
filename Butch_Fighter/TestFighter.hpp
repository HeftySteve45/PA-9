#pragma once
#include <iostream>
#include <windows.h>
#include "SFML/Graphics.hpp"
#include "Fighter.hpp"

using std::cout;

class TestFighter : public Fighter
{
public:
	TestFighter();

	void RunFighterTest();
	
private:
	sf::RenderWindow *mTestWindow;
	void TestDraw();
	bool TestLoadSprite();
	void TestAttackSound();


	//not used in testing, only used to prevent errors due to them being pure virtual functions
	void update(float a,bool b);
	void loadTextures();
};

TestFighter::TestFighter()
{
	this->mTestWindow = new sf::RenderWindow(sf::VideoMode(1440, 760), "Fighter Test Window");
	
}

//Calls all the fighter test functions
void TestFighter::RunFighterTest()
{
	if (TestLoadSprite())
	{
		TestDraw();
		TestAttackSound();
	}
}

//draws the sprite sheet to the window
void TestFighter::TestDraw()
{
	cout << "Running Sprite sheet Draw Test\n";
	mTestWindow->clear();
	draw(*mTestWindow);
	mTestWindow->display();
	Sleep(1000);
}

//loads a specified sprite sheet from a file
bool TestFighter::TestLoadSprite()
{
	bool success = false;
	cout << "Running Sprite Sheet Load Test\n";
	if (this->_Texture.loadFromFile("Butch_Sprites.png"))
	{
		cout << "File Load Pass\n";
		this->_sprite.setTexture(this->_Texture);
		
		success = true;
	}
	else
	{
		cout << "File Load Fail\n";
	}
	Sleep(3000);
	return success;
}

//tests the punch attack sound
void TestFighter::TestAttackSound()
{
	cout << "Running Attack Sound Test\n";

	this->loadAtkSound("Punch.wav");
	for (int i = 0; i < 5; i++)
	{
		cout << "Playing...\n";
		this->_atkSound.play();
		Sleep(500);	
	}
}

//Not Used
void TestFighter::update(float a, bool b)
{
}

void TestFighter::loadTextures()
{
}