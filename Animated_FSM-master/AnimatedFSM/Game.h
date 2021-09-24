#pragma once
#include "Animation.h"
#include "State.h"
#include <iostream>

class Game
{
public:

//	Animation myAnimation;
	/*sf::Texture playerLandingSpriteSheet;*/

	// used to determine which animation the player should be displaying
	bool canPlayerIdle = true;
	bool canPlayerRunRight = false;
	bool canPlayerRunLeft = false;
	bool canPlayerJump = false;
	bool canPlayerCheckDagger = false;
	bool canPlayerGlide = false;

	// used to play the full animation when the button is pressed. (except for double jump because it doesn't work)
	bool isPlayerJumping = false;
	bool isPlayerCheckingDagger = false;
	bool isDoubleJumpPressed = false;


	Game();

	void run();
	void draw();
	void update();
	void movePlayerRight();
	void movePlayerLeft();
	void movePlayerUp();
	void movePlayerDown();
	//void animatedLanding();

	// used to keep track of how long some animations have been displayed for
	int timer = 0;

};