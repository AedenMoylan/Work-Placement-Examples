
#include "Game.h"

Animation fsm;

sf::RenderWindow window(sf::VideoMode(800, 600), "Animated FSM");


	Game::Game()
	{

	}


	void Game::run()
		// This function contains the main game loop which controls the game. 
	{
		

		//if (!playerLandingSpriteSheet.loadFromFile("./assets/Slide.png"))
		//{
		//	std::cout << "error loading texture" << std::endl;
		//}

		srand(time(nullptr)); // set the seed once

		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

		sf::Time timeSinceLastUpdate = sf::Time::Zero;

		// the clock object keeps the time.
		sf::Clock clock;


		clock.restart();

		while (window.isOpen())
		{
			// check if the close window button is clicked on
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//get the time since last update and restart the clock
			timeSinceLastUpdate += clock.restart();

			//update every 60th of a second
			//only when the time since last update is greater than 1/60 update the world.
			if (timeSinceLastUpdate > timePerFrame)
			{

				draw();

				update();

				// reset the timeSinceLastUpdate to 0 
				timeSinceLastUpdate = sf::Time::Zero;
			}
		}  // end while loop

	}

	// draws the player sprite and clears the window
	void Game::draw()
	{
			window.clear();
		window.draw(fsm.playerSprite);
		window.display();
	}

	// handles keyboard input and switching of animation states
	void Game::update()
	{
		// sets other bools to false so only that animation can play
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				canPlayerIdle = false;
				canPlayerRunRight = true;
				canPlayerRunLeft = false;
				canPlayerJump = false;
				canPlayerCheckDagger = false;
				canPlayerGlide = false;

			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				canPlayerIdle = false;
				canPlayerRunRight = false;
				canPlayerRunLeft = true;
				canPlayerJump = false;
				canPlayerCheckDagger = false;
				canPlayerGlide = false;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				canPlayerIdle = false;
				canPlayerRunRight = false;
				canPlayerRunLeft = false;
				canPlayerJump = false;
				canPlayerCheckDagger = true;
				canPlayerGlide = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				canPlayerIdle = false;
				canPlayerRunRight = false;
				canPlayerRunLeft = false;
				canPlayerJump = true;
				canPlayerCheckDagger = false;
				canPlayerGlide = false;
			}




			// if these buttons aren't pressed or player isn't jumping or checking dagger, play idle animation
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
				(!sf::Keyboard::isKeyPressed(sf::Keyboard::Z ) &&
					(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
						(isPlayerJumping == false) &&
						    (isPlayerCheckingDagger == false)))))
		{
			// resets animation frames for smoother animations
			fsm.animationFrameJumping = 0;
			fsm.animationFrameGlide = 0;
			fsm.animationFrameMoveLeft = 0;
			fsm.animationFrameMoveRight = 0;
			fsm.animationFrameCheckDagger = 0;

			
			
			canPlayerIdle = true;
			canPlayerRunRight = false;
			canPlayerRunLeft = false;
			canPlayerJump = false;
			canPlayerCheckDagger = false;
			canPlayerGlide = false;
		}
		// checks if bool is true and then sets animation state
		if (canPlayerIdle == true)
		{
				fsm.animateIdle();
		}

		if (canPlayerRunRight == true)
		{
			fsm.animateRunRight();
			// moves player right 2 pixels when pressed
			movePlayerRight();
		}

		if (canPlayerRunLeft == true)
		{
			fsm.animateRunLeft();
			movePlayerLeft();
		}

		if (canPlayerJump == true)
		{
			// timer used to display other animation states during jumping animation
			if (timer < 100)
			{
				isPlayerJumping = true;
				timer++;
				fsm.animateJump();

			}
			if (timer < 20)
			{
				// moves player up to simulate jump
				movePlayerUp();
				// was going to be used for double jump but since I couldn't make a texture it didn't work
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					
					isDoubleJumpPressed == true;
				}
			}
			if (timer > 20)
			{
				// was supposed to replay the jumping animation again
				if (isDoubleJumpPressed == true)
				{
					fsm.animationFrameJumping = 0;
					fsm.animateJump();

					
				}
		// changes animation and moves downwards
				fsm.animatedGlide();
				movePlayerDown();
			}

			if (timer >= 100)
			{
				// lets player be able to do other animations again
				isPlayerJumping = false;
				canPlayerJump = false;
				timer = 0;
			//	animatedLanding();
			}
		}

		if (canPlayerCheckDagger == true)
		{
			//dagger animation plays evenif button isn't held
			if (timer < 30)
			{
				isPlayerCheckingDagger = true;
				timer++;
				fsm.animateCheckDagger();
			}
			else if (timer >= 30)
			{
				timer = 0;
				isPlayerCheckingDagger = false;
				fsm.animationFrameCheckDagger = 0;
			}
		}

	}

	// used to move player sprite in different directions
	void Game::movePlayerRight()
	{
		fsm.playerSprite.move(2, 0);
	}

	void Game::movePlayerLeft()
	{
		fsm.playerSprite.move(-2, 0);
	}

	void Game::movePlayerUp()
	{
		fsm.playerSprite.move(0, -8);
	}

	void Game::movePlayerDown()
	{
		fsm.playerSprite.move(0, 2);
	}

	//void Game::animatedLanding()
	//{
	//	fsm.playerSprite.setTexture(playerLandingSpriteSheet);
	//	fsm.totalTimeElapsed++;
	//	if (fsm.totalTimeElapsed > 10)
	//	{
	//		fsm.totalTimeElapsed = 0;
	//		animationFrameLanding++;
	//		if (animationFrameLanding > 10)
	//		{
	//			animationFrameLanding = 0;
	//		}
	//	}
	//	int col = animationFrameLanding % 3;
	//	int row = animationFrameLanding / 4;
	//	fsm.playerRect.height = 351;
	//	fsm.playerRect.width = 373;
	//	fsm.playerRect.left = col * fsm.playerRect.width;
	//	fsm.playerRect.top = row * fsm.playerRect.height;
	//	fsm.playerSprite.setTextureRect(fsm.playerRect);
	//}