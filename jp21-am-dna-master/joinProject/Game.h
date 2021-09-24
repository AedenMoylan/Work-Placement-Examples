#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenSize.h"
#include "Zombie.h"
#include "Background.h"
#include "Player.h"
#include "AmmoBox.h"
#include "CollisionDetection.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "GameState.h"
#include "Menu.h"
#include "Particles.h"
#include "HUD.h"
#include "CharacterSelection.h"
#include "Grid.h"
#include "ScreenSize.h"


class Game
{
public:
	/// <summary>
	/// @brief Default constructor that initialises the SFML window, 
	///   and sets vertical sync enabled. 
	/// </summary>
	Game();

	/// <summary>
	/// @brief the main game loop.
	/// 
	/// A complete loop involves processing SFML events, updating and drawing all game objects.
	/// The actual elapsed time for a single game loop results (lag) is stored. If this value is 
	///  greater than the notional time for one loop (MS_PER_UPDATE), then additional updates will be 
	///  performed until the lag is less than the notional time for one loop.
	/// The target is one update and one render cycle per game loop, but slower PCs may 
	///  perform more update than render operations in one loop.
	/// </summary>
	void run();

protected:

	/// <summary>
	/// @brief Placeholder to perform updates to all game objects.
	/// </summary>
	/// <param name="time">update delta time</param>
	void update(double dt);

	/// <summary>
	/// @brief Draws the background and foreground game objects in the SFML window.
	/// The render window is always cleared to black before anything is drawn.
	/// </summary>
	void render();

	/// <summary>
	/// @brief Checks for events.
	/// Allows window to function and exit. 
	/// Events are passed on to the Game::processGameEvents() method.
	/// </summary>	
	void processEvents();

	/// <summary>
	/// @brief Handles all user input.
	/// </summary>
	/// <param name="event">system event</param>
	void processGameEvents(sf::Event&);

	/// <summary>
	/// calls functions from collisionCaller to detect collisions
	/// </summary>
	void collisionCaller();

	/// <summary>
	/// sets up the victory text and lose text
	/// </summary>
	/// <param name="font"></param>
	void setUpText(sf::Font& font);
	// main window

	// instances
	sf::RenderWindow m_window;
	Zombie myZombie;
	Background myBackground;
	Player myPlayer;
	Ammobox myAmmoBox;
	Bullet myBullet;
	CollisionDetection myCollisionDetection;
	Obstacle myObstacle;
	GameState m_gameState;
	Menu myMenu;
	Particles myParticles;
	ParticleSystem myParticleSystem;
	HUD myHUD;
	CharacterSelection myCharacterSelection;
	Grid myGrid;
	ScreenSize myScreenSize;

	sf::Font m_font;

	// true when space is pressed
	bool hasSpaceBeenPressed = false;

	// when true player can shoot. false when bullet is active
	bool canShoot = true;


	// changes player texture based on the selectionNumber
	int chosenTexture = 0;

	// true when zombie reaches the destination cell
	bool isDestinationReached = false;

	int m_nextIndex;
	std::vector<int> path;
	sf::Vector2f nextLocation;

	bool setNextLocation = false;

	// win and lose text
	sf::Text victoryText;
	sf::Text loseText;

};
