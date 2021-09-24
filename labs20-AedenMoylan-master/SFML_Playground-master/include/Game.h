#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenSize.h"
#include "Tank.h"
#include "LevelLoader.h"
#include "CollisionDetector.h"
#include "TankAI.h"
#include "GameState.h"
#include "HUD.h"
#include "Fuel.h"
#include "Bitcoin.h"


/// <summary>
/// @brief Main class for the SFML Playground project.
/// 
/// This will be a single class framework for learning about SFML. 
/// Example usage:
///		Game game;
///		game.run();
/// </summary>

class Game
{
public:
	LevelData m_level;
	Tank myTank;
	TankAi m_aiTank;
	Fuel myFuel;
	Bitcoin myBitcoin;

	//Target myTarget;
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
	void update(double dt ,Tank const& playerTank );

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
/// @brief Creates the wall sprites and loads them into a vector.
/// Note that sf::Sprite is considered a light weight class, so 
///  storing copies (instead of pointers to sf::Sprite) in std::vector is acceptable.
/// </summary>
	void generateWalls();

	// Creates the target sprites and loads them into a vector.
	void generateTargets();

	/// <summary>
	/// detects the collisions of 2 classes. e.g. bullet (from tank class) combining with target (from target class)
	/// </summary>
	void detectCollisions();
	
	/// <summary>
	/// // counts down the timer of the game and calls functions when it <= 0
	/// </summary>
	void gameTimerCountdown();

	// starts a random number generator that randomly decides which target sprite will spawn at a time
	void nextTarget();

	// detects when the warning sprite should be displayed and sets the position of the warning target to the regular target
	void targetTimerCountdown();

	// calculates the players hit accuracy
	void calculateAverage();

	// stops all the stuff that should be stopped when the game ends. also stops the tank sounds from playing
	void stopDrawing();

	void checkEnemyHealth();

	void checkBoundaries();

	std::function<void(int)> m_funcApplyDamage;
	// main window
	sf::RenderWindow m_window;

	/*Tank const& playerTank;*/
	// used to store the player's score
	int score = 0;

	// size of the array used to set the target positions
	const int TARGET_ARRAY_SIZE = 7;

	// this number gets randomly generated and randomises the target spawns
	int randomNumForTarget = 0;
	// font used to display on the screen with
	sf::Font m_font;
	// text used to display the score
	sf::Text m_scoreText;
	// text used to display the timer
	sf::Text m_timerText;
	// text used to display the score
	sf::Text m_accuracyText;
	// text used to display the victory message
	sf::Text m_victoryText;
	// used for the timer to keep track of how long is left on the timer
	sf::Text m_objectiveText;

	sf::Clock gameTimer;
	// used to keep track of how long a target has been active for
	sf::Clock targetTimer;

	// sprite and texture for background
	sf::Sprite m_bgSprite;
	sf::Texture m_bgTexture;

	sf::Sprite m_jerryCanSprite;
	sf::Texture m_jerryCanTexture;

	// sprite for wall
	sf::Sprite wallSprite;

	// sprite for warning target. Displays when the target timer has almost ran out
	sf::Sprite m_target2Sprite;
	// texture of warning target
	sf::Texture m_target2Texture;

	// sound and buffer of the song playing in the 
	sf::Sound m_backgroundSong;
	sf::SoundBuffer m_backgroundMusicBuffer;

	// sound and buffer of the sound that plays when a target is hit 
	sf::Sound m_targetPing;
	sf::SoundBuffer m_targetPingBuffer;

	sf::Time timeOfGame;
	// texture of target
	sf::Texture m_targetTexture;

	// sprite and texture of victory screen
	sf::Sprite m_victorySprite;
	sf::Texture m_victoryTexture;

	sf::Sprite m_bankSprite;
	sf::Texture m_bankTexture;
	

	// the amount of seconds until a timer changes location
	int numberToRespawn = 8  ;
	// number of times the player hits a target
	float targetsHit{ 0.0 };
	// time between game lose to game restart
	sf::Time timeToRestart;

	const int TIME_BETWEEN_RESTART_VALUE = 2000;

	// average number of targets hit per game
	float average = { 0.0 };
	// becomes true when the timer has run out
	bool isGameOver = false;
	// used to spawn a warning target when target timer is low
	bool isTargetTimeLow = false;
	// another bool that becomes true when the game ends
	bool gameEnded = false;
	// The initial game state set to GAME_RUNNING
	GameState m_gameState{ GameState::GAME_RUNNING };
	//bool playFireSound = false;

	//std::Vectors that stores the walls and targets
	std::vector<sf::Sprite> m_wallSprites;
	std::vector<sf::Sprite> m_targetVector;


	// A texture for the sprite sheet 
	sf::Texture m_spriteSheetTexture;
	sf::Texture m_texture;

	//// The font to be used for the HUD.
	//sf::Font m_font;

	// The game HUD instance.
	HUD m_hud;

	void restartGame();
};
