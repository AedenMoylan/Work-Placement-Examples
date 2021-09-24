#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Animation
{
	class State* current;
public:

	sf::Texture playerIdleTextureSheet;
	sf::Texture playerRunRightTextureSheet;
	sf::Texture playerRunLeftTextureSheet;
	sf::Texture playerJumpTextureSheet;
	sf::Texture playerCheckDaggerTextureSheet;
	sf::Texture playerGlideTextureSheet;

	sf::Sprite playerSprite;
	sf::IntRect playerRect;

	float totalTimeElapsed = 0;
	int animationFrameIdle = 0;
	int animationFrameCheckDagger = 0;
	int animationFrameGlide = 0;
	int animationFrameMoveLeft = 0;
	int animationFrameMoveRight = 0;
	int animationFrameJumping = 0;

	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
	void doubleJumping();
	void checkDagger();
	void movePlayer();

	void animateIdle();
	void animateRunRight();
	void animateRunLeft();
	void animateJump();
	void animateCheckDagger();
	void animatedGlide();
};

