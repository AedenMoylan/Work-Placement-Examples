#include "Game.h"
#include <iostream>

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "SFML Playground", sf::Style::Default),
	myZombie(myZombie.zombieSpriteSheet),
	myPlayer(myPlayer.playerSpriteSheet)
{
	if (!myZombie.zombieTextureSheet.loadFromFile("./resources/images/zombieSpriteSheet2.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!myBullet.bulletTexture.loadFromFile("./resources/images/bullet.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!m_font.loadFromFile("./resources/fonts/ZOMBIE.TTF"))
	{
		std::cout << "error with font file file";
	}

	m_window.setVerticalSyncEnabled(true);

	myZombie.zombieSpriteSheet.setTexture(myZombie.zombieTextureSheet);

	myZombie.init();
	myPlayer.init();
	myBackground.backgroundInit();
	myAmmoBox.init();
	myBullet.init();
	myObstacle.init();
	myMenu.initialise(m_font);
	myHUD.init(m_font);
	myGrid.init();
	myCharacterSelection.setupSprites(m_font);

	myZombie.startAnimation(Zombie::ZombieAnimationState::walk);
	myPlayer.startAnimation(Player::PlayerAnimationState::walk);

	m_gameState = GameState::GAME_MENU;

	myGrid.markImpassableCells(myObstacle);	

	path = myGrid.breadthFirst(1, 415);

	m_nextIndex = path.size() - 1;
	nextLocation = myGrid.getCells().at(path.at(m_nextIndex)).getPosition(); // get the next location for zombie to go 

	setUpText(m_font);
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		case sf::Keyboard::Up:
			// Up key was pressed...
			break;
		default:
			break;
		}
	}
}

void Game::collisionCaller()
{
	if (myCollisionDetection.player_ammoBox_Collision(myPlayer.spriteSheet, myAmmoBox.getSprite()))
	{
		myAmmoBox.setIsAmmoCollected(true);
	};
	if (myCollisionDetection.player_greenContainer_Collision(myPlayer.spriteSheet, myObstacle.getContainerSprite()) == true)
	{
		std::cout << "collision detected container " << std::endl;
	};

	if (myCollisionDetection.bullet_zombie_Collision(myBullet.bulletSprite, myZombie.spriteSheet) == true)
	{
		myBullet.despawnBullet();
		
		myZombie.reduceHealth();

		myHUD.numBulletsToDraw -= 1;

		canShoot = true;

		if (myZombie.getHealth() <= 0)
		{
			m_gameState = GameState::GAME_WIN;
		}
	};

	if (myCollisionDetection.player_zombie_Collision(myPlayer.spriteSheet, myZombie.spriteSheet) == true)
	{
		m_gameState = GameState::GAME_LOSE;
	};

	for (int i = 0; i < myObstacle.getMaxObstacles(); i++)
	{
		if (myCollisionDetection.bullet_obstacle_collision(myBullet.bulletSprite, myObstacle.getObstacles(i)))
		{
			myBullet.despawnBullet();
			myHUD.numBulletsToDraw -= 1;
			canShoot = true;
		}
	}

	for (int i = 0; i < myObstacle.getMaxObstacles(); i++)
	{
		if (myCollisionDetection.player_obstacle_Collision(myPlayer.spriteSheet, myObstacle.getObstacles(i)))
		{
			myPlayer.updateSpeed(0);
		}
	}

}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_gameState = GameState::GAME_MENU;
	}

	switch (m_gameState)
	{
	case GameState::GAME_RUNNING:
		myMenu.changeVolume();
		myPlayer.Update();
		collisionCaller();

		if (hasSpaceBeenPressed == true)
		{
			myParticles.Update();
			myParticleSystem.Update();
		}
		else
		{
			myBullet.setIsBulletActive(true);
		}

	
		if (canShoot == true && myBullet.numberOfBullet > 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				hasSpaceBeenPressed = true;

				if (myAmmoBox.getIsAmmoCollected() )
				{

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
					{
						myParticleSystem.Initialise(myPlayer.spriteSheet.getPosition());

						myBullet.setBulletPosition(myPlayer.spriteSheet);

						myBullet.setRotation(myPlayer.spriteSheet);

						myBullet.setCounter(0);

						myBullet.numberOfBullet -= 1;

						myPlayer.playGunSound();

						canShoot = false;
					}
				}

			}
		}
		myBullet.update();

		if (path.empty() == false ) // if its not empty 
		{
			if (setNextLocation == true)
			{
				nextLocation = myGrid.getCells().at(path.at(m_nextIndex)).getPosition(); // get the next location for zombie to go 
				setNextLocation = false;
			}

			if (myZombie.getPosition() != nextLocation)
			{
				myZombie.move(nextLocation);
			}
			else if (myZombie.getPosition() == nextLocation)
			{
				isDestinationReached = true;
				path.pop_back();
				m_nextIndex = path.size() - 1;
				setNextLocation = true;
			}

		}

		break;

	case GameState::GAME_WIN:
		std::cout << "winner" << std::endl;
		
		break;

	case GameState::GAME_MENU:
		myMenu.update(m_window);

		if (myMenu.getSelectionNumber() == 1)
		{
			m_gameState = GameState::GAME_RUNNING;
		}

		if (myMenu.getSelectionNumber() == 2)
		{
			m_gameState = GameState::CHARACTER_OPTION;
		}

		if (myMenu.getSelectionNumber() == 3)
		{
			m_gameState = GameState::GAME_RUNNING;
		}

	case GameState::CHARACTER_OPTION:
		myCharacterSelection.update(m_window);

		chosenTexture = myCharacterSelection.getSelectionNumber();

		if (chosenTexture == 1)
		{
			myPlayer.chooseTexture(chosenTexture);
			m_gameState = GameState::GAME_MENU;
		}

		if (chosenTexture == 2)
		{
			myPlayer.chooseTexture(chosenTexture);
			m_gameState = GameState::GAME_MENU;
		}

		if (chosenTexture == 3)
		{
			myPlayer.chooseTexture(chosenTexture);
			m_gameState = GameState::GAME_MENU;
		}
	}
}



////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	switch (m_gameState)
	{
	case GameState::GAME_RUNNING:

		myBackground.draw(m_window);
		myZombie.Draw(m_window);
		myPlayer.Draw(m_window);
		myAmmoBox.draw(m_window);
		myBullet.draw(m_window);
		myObstacle.draw(m_window);
		myParticles.Draw(m_window);
		myParticleSystem.Draw(m_window);
		myGrid.draw(m_window);
		
		myHUD.draw(m_window, myAmmoBox.getIsAmmoCollected());
		

	break;

	case GameState::GAME_WIN:
		std::cout << "stop drawing" << std::endl;
		myBackground.drawVictory(m_window);
		m_window.draw(victoryText);
		break;

	case GameState::GAME_LOSE:
		myBackground.drawLose(m_window);
		m_window.draw(loseText);
		break;

	case GameState::GAME_MENU:
		myMenu.draw(m_window);
		break;

	case GameState::CHARACTER_OPTION:
		myCharacterSelection.draw(m_window);
	}
	m_window.display();
}

void Game::setUpText(sf::Font& font)
{
	victoryText.setFont(m_font);
	victoryText.setString("You Survived... For Now ");
	victoryText.setPosition(myScreenSize.s_width / 2, myScreenSize.s_height / 2);
	victoryText.setCharacterSize(30);
	victoryText.setFillColor(sf::Color::Red);

	loseText.setFont(m_font);
	loseText.setString("git gud ");
	loseText.setPosition(myScreenSize.s_width / 2, myScreenSize.s_height / 2);
	loseText.setCharacterSize(30);
	loseText.setFillColor(sf::Color::Red);

}




