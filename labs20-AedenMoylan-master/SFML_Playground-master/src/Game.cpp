/// <summary>
/// Name : Aeden Moylan C00249220
/// 
/// Time : 38 hours
/// 
/// quick summary: you have about a minute to hit as much targets as you can. tank turret can be rotated. targets disappear after about 8 seconds
/// </summary>
#include "Game.h"
#include <iostream>
#include <Thor/Vectors.hpp>


// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "SFML Playground", sf::Style::Default)
	, myTank(m_texture, m_wallSprites)
	, m_aiTank(m_texture, m_wallSprites)    
	, m_hud(m_font) // Add this line
{
	srand(time(NULL));

	m_window.setVerticalSyncEnabled(true);

	int currentLevel = 1;

	timeOfGame = sf::milliseconds(m_level.m_tank.duration);

	timeToRestart = sf::milliseconds(TIME_BETWEEN_RESTART_VALUE);

	// will Generate an exception if any of these texture or buffer setters have an issue ***************
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}
	catch (std::exception & e)
	{
		std::cout << "Level loading failure " << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}


	if (!m_texture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	if (!m_bankTexture.loadFromFile("./resources/images/bank.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	m_bankSprite.setTexture(m_bankTexture);
	m_bankSprite.setPosition(1200, 550);
	m_bankSprite.setScale(0.2, 0.2);

	if (!m_font.loadFromFile("./resources/fonts/18ARMY.otf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}

	//if (!m_bgTexture.loadFromFile("./resources/images/wood.jpg"))
	//{
	//	std::string s("Error loading the texture");
	//	throw std::exception(s.c_str());
	//}

	m_bgSprite.setTexture(m_bgTexture);

	if (!m_spriteSheetTexture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string errorMsg("Error loading texture");
		throw std::exception(errorMsg.c_str());
	}

	if (!m_targetTexture.loadFromFile("./resources/images/target.png"))
	{
		std::string errorMsg("Error loading texture");
		throw std::exception(errorMsg.c_str());
	}

	if (!m_target2Texture.loadFromFile("./resources/images/target2.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}



	if (!m_victoryTexture.loadFromFile("./resources/images/victoryBackground.jpg"))
	{
		std::string errorMsg("Error loading texture");
		throw std::exception(errorMsg.c_str());
	}

	m_victorySprite.setTexture(m_victoryTexture);

	if (!m_backgroundMusicBuffer.loadFromFile("./resources/audio/backgroundMusic.wav"))
	{
		std::string s("Error loading audio");
		throw std::exception(s.c_str());
	}

	if (!m_targetPingBuffer.loadFromFile("./resources/audio/metalPing.wav"))
	{
		std::string s("Error loading audio");
		throw std::exception(s.c_str());
	}

	if (!m_jerryCanTexture.loadFromFile("./resources/images/jerry.png"))
	{
		std::string errorMsg("Error loading texture");
		throw std::exception(errorMsg.c_str());
	}

	m_jerryCanSprite.setTexture(m_jerryCanTexture);

//	m_backgroundSong.setBuffer(m_backgroundMusicBuffer);
	m_targetPing.setBuffer(m_targetPingBuffer);
	m_target2Sprite.setTexture(m_target2Texture);
	generateWalls();
	generateTargets();

	m_scoreText.setFont(m_font);  // set the font for the text
	m_scoreText.setCharacterSize(40); // set the text size
	m_scoreText.setFillColor(sf::Color::Red); // set the text colour
	m_scoreText.setPosition(50, 50);  // its position on the screen
	                                  // same for the other texts
	m_timerText.setFont(m_font);
	m_timerText.setCharacterSize(40);
	m_timerText.setFillColor(sf::Color::Red);
	m_timerText.setPosition(1200, 50);

	m_accuracyText.setFont(m_font);
	m_accuracyText.setCharacterSize(40);
	m_accuracyText.setFillColor(sf::Color::White);
	m_accuracyText.setPosition(825, 750);

	m_victoryText.setFont(m_font);
	m_victoryText.setCharacterSize(80);
	m_victoryText.setFillColor(sf::Color::White);
	m_victoryText.setPosition(375, 300);

	
	// plays the background music
//	m_backgroundSong.play();

	m_aiTank.init(m_level.m_aiTank.m_position);

	myFuel.init();

	myBitcoin.init();
	//m_gameState = GameState::GAME_RUNNING;


		// Point at TankAI::applyDamage()...this function expects 1 argument (damage amount), but that argument
		//  will be supplied later when we call the function inside Projectile::udpate()
		// So we use what is called a placeholder argument and this will be substituted later with the damage amount
	using std::placeholders::_1;
	// The parameters of bind are the function to be called, followed by the name of the target instance, 
	//  followed by the placeholder argument.
	m_funcApplyDamage = std::bind(&TankAi::applyDamage, &m_aiTank, _1);

}


void Game::generateWalls()
{
	sf::IntRect wallRect(2, 129, 33, 23);
	// Create the Walls 
	for (ObstacleData const& obstacle : m_level.m_obstacles)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_spriteSheetTexture);
		sprite.setTextureRect(wallRect);
		sprite.setOrigin(wallRect.width / 2.0, wallRect.height / 2.0);
		sprite.setPosition(obstacle.m_position);
		sprite.setRotation(obstacle.m_rotation);
		m_wallSprites.push_back(sprite);
	}


}
// Creates the target sprites and loads them into a vector.
void Game::generateTargets()
{
	for (TargetData const& target : m_level.m_targets)
	{
		sf::Sprite sprite;
		sprite.setTexture(m_targetTexture);
		sprite.setPosition(target.m_position);
		sprite.setOrigin(32, 32);
		sprite.setScale(0.25, 0.25);
		m_targetVector.push_back(sprite);
	}
	m_target2Sprite.setOrigin(32, 32);
	m_target2Sprite.setScale(0.25, 0.25);
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
			update(lag,myTank);
			lag -= MS_PER_UPDATE;
		}
		update( lag,myTank );

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

}





////////////////////////////////////////////////////////////
void Game::update( double dt, Tank const& playerTank)
{

//	m_hud.update(m_gameState);
	switch (m_gameState)
	{
	case GameState::GAME_RUNNING:
		checkEnemyHealth();
		m_aiTank.update(myTank, dt);
		myTank.update(dt, m_funcApplyDamage, m_aiTank.getTankBase());

		myTank.handleKeyInput();

        m_hud.update(m_gameState);
        detectCollisions();
        gameTimerCountdown();
        timeOfGame = timeOfGame - sf::milliseconds(6);
        targetTimerCountdown();
		myFuel.decreaseFuel(myTank.m_speed);
		myFuel.setRectangleSize();
		checkBoundaries();
		if (myFuel.fuelAmount <= 0)
		{
			m_gameState = GameState::GAME_LOSE;
		}
		if (myBitcoin.didPlayerCollectCoin == true)
		{
			myBitcoin.update(myTank.getPosition());
		}
		
		break;

	case GameState::GAME_WIN:
		m_hud.m_gameStateText.setString("You Win");
		break;

	case GameState::GAME_LOSE:
	//m_hud	m_gameStateText.setString("You Lost");
		m_hud.m_gameStateText.setString("You Lost");

		timeToRestart = timeToRestart - sf::milliseconds(6);

		if (timeToRestart <= sf::milliseconds(0))
		{
			restartGame();
		

			m_gameState = GameState::GAME_RUNNING;
		}

	

		break;

	default:
		std::cout << "Error occured" << std::endl;
		break;
	}
}





////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	if (isGameOver == false)
	{
		// Render your sprites here....
		m_bgSprite.setScale(2.1, 2.1);
		m_victorySprite.setScale(1.9, 1.9);
		m_window.draw(m_bgSprite);
		m_window.draw(myBitcoin.m_bitcoinSprite);
		myTank.render(m_window);
		m_aiTank.render(m_window);
		m_hud.render(m_window);
		myFuel.draw(m_window);
		m_window.draw(myFuel.m_fuelText);
		m_window.draw(myFuel.m_fuelShape);
		myBitcoin.draw(m_window);
		m_window.draw(m_bankSprite);
		

		for (int i = 0; i < m_wallSprites.size(); i++)
		{
			m_window.draw(m_wallSprites.at(i));
		}

		m_window.draw(m_targetVector[randomNumForTarget]);
		if (timeOfGame <= sf::milliseconds(1999))
		{
			m_window.draw(m_target2Sprite);
		}
	m_window.draw(m_timerText);

	}

		// draw the score to the screen as it gets updated
	m_scoreText.setString(" SCORE : " + std::to_string(score));

	m_accuracyText.setString(" ACCURACY : " + std::to_string(average) + " Percent ");

	m_victoryText.setString(" GOOD WORK SOLDIER! ");


	if (isGameOver == true)
	{
		m_window.draw(m_victorySprite);

		m_window.draw(m_accuracyText);

		m_window.draw(m_victoryText);

	}


	m_window.draw(m_scoreText);
	m_window.display();
}

// detects collisions between bullet and targets
void Game::detectCollisions()
{
	if (isGameOver == false)
	{
		if (CollisionDetector::collision(myTank.getBulletBody(), m_targetVector[randomNumForTarget]))
		{
			m_targetPing.play();
			timeOfGame = timeOfGame + sf::milliseconds(6000);
			numberToRespawn += 6;
			score += 10;
 			nextTarget();
			targetsHit++;
		}

		if (CollisionDetector::collision(myTank.getBase(), myFuel.getFuel()))
		{
			myFuel.fuelAmount = myFuel.fuelStartAmount;
		}

		if (CollisionDetector::collision(myBitcoin.m_bitcoinSprite, myTank.getBase()))
		{
			myBitcoin.didPlayerCollectCoin = true;

		}


		if (CollisionDetector::collision(myBitcoin.m_bitcoinSprite, m_bankSprite))
		{
			m_gameState = GameState::GAME_WIN;

		}

		//if (CollisionDetector::collision(myTank.getBase(), m_aiTank.getBase()))
		//{
		//	GameState m_gameState{ GameState::GAME_LOSE };
		//}

		bool collision = m_aiTank.collidesWithPlayer(myTank);

		if (collision == true)
		{

		//	GameState m_gameState{ GameState::GAME_LOSE };
			m_gameState = GameState::GAME_LOSE;
		}
	}
}

// counts down the timer of the game and calls functions when it <= 0
void Game::gameTimerCountdown()
{
	int timer = gameTimer.getElapsedTime().asSeconds();

	int remainingTime = 60;
	remainingTime -= timer;

	m_timerText.setString("Time : " + std::to_string(remainingTime));

	if (remainingTime <= 0)
	{
		calculateAverage();
		stopDrawing();
	}
}

// starts a random number generator that randomly decides which target sprite will spawn at a time
void Game::nextTarget()
{
	int currentNum = randomNumForTarget;

	while (randomNumForTarget == currentNum)
	{
		randomNumForTarget = rand() % TARGET_ARRAY_SIZE;
	}
}
// detects when the warning sprite should be displayed and sets the position of the warning target to the regular target
void Game::targetTimerCountdown()
{
	if (timeOfGame <= sf::milliseconds(2000))
	{
			sf::Vector2f spritePosition = m_targetVector[randomNumForTarget].getPosition();
			m_target2Sprite.setPosition(spritePosition.x, spritePosition.y);

		isTargetTimeLow = true;
		if (timeOfGame <= sf::milliseconds(0))
		{
			timeOfGame = sf::milliseconds(m_level.m_tank.duration);
			nextTarget();
			isTargetTimeLow = false;
		}
	}
}
// calculates the players hit accuracy
void Game::calculateAverage()
{
	if (gameEnded == false)
	{
		if (myTank.shotsFired > 0)
		{
			gameEnded = true;

			myTank.shotsFired--;
			average = (targetsHit / myTank.shotsFired * 100);
			std::cout << average << std::endl;
		}
	}
}
// stops all the stuff that should be stopped when the game ends. also stops the tank sounds from playing
void Game::stopDrawing()
{
	isGameOver = true;
	myTank.m_drivingSound.stop();
	myTank.m_shootingSound.stop();
}

void Game::restartGame()
{
	myTank.tankStartPosition();
	//myTank.setPosition();
	m_aiTank.init(m_level.m_aiTank.m_position);
	timeToRestart = sf::milliseconds(TIME_BETWEEN_RESTART_VALUE);
	m_gameState = GameState::GAME_RUNNING;
	score = 0;
	myTank.m_speed = 0;
}

void Game::checkEnemyHealth()
{
	if (m_aiTank.tankHealth <= 0)
	{
		m_gameState = GameState::GAME_WIN;
	}
}

void Game::checkBoundaries()
{
	sf::Vector2f playerPosition = myTank.getPosition();
	sf::Vector2f enemyPosition = m_aiTank.getPosition();
	if (playerPosition.x > 1450)
	{
		playerPosition.x = 10;
	}
	else if (playerPosition.x < -10)
	{
		playerPosition.x = 1430;
	}

	else if (playerPosition.y > 910)
	{
		playerPosition.y = 0;
	}
	else if (playerPosition.y < -10)
	{
		playerPosition.y = 900;
	}




	if (enemyPosition.x > 1450)
	{
		enemyPosition.x = 10;
	}
	else if (enemyPosition.x < -10)
	{
		enemyPosition.x = 1430;
	}

	else if (enemyPosition.y > 910)
	{
		enemyPosition.y = 0;
	}
	else if (enemyPosition.y < -10)
	{
		enemyPosition.y = 900;
	}

	myTank.m_tankBase.setPosition(playerPosition.x, playerPosition.y);

	m_aiTank.m_tankBase.setPosition(enemyPosition.x, enemyPosition.y);
}