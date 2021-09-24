#pragma once
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "MathUtility.h"



class Player
{


public:

	Player(sf::Sprite& spheet) : spriteSheet(spheet)
	{
	}

	/// <summary>
	/// sprite sheet for the player
	/// </summary>
	sf::Sprite playerSpriteSheet;


	enum class PlayerAnimationState { walk, run, jump, idle };
	PlayerAnimationState animationState = PlayerAnimationState::walk;
	Animation animations[5];
	AnimationSheet animSheet;
	sf::Vector2f position;
	sf::Sprite& spriteSheet;

	/// <summary>
	/// initialises information to do with animating the player
	/// </summary>
	void InitAnimationData();

	/// <summary>
	/// sets the animation state and starts the animation
	/// </summary>
	/// <param name="_animationState"></param>
	void startAnimation(PlayerAnimationState _animationState);

	/// <summary>
	/// draws spriteSheet and calls the next frame in the animation.
	/// also sets the textrect to match the size of the frame
	/// </summary>
	/// <param name="win"></param>
	void Draw(sf::RenderWindow& win);

	/// <summary>
	/// used to update player mechanics. calls detectMovementInput()
	/// </summary>
	void Update();

	/// <summary>
	/// loads textures and wav files. sets buffer to sounds and textures to sprites. 
	/// sets initial values for rotation, move speed, and rotation speed
	/// calls initAnimationData()
	/// sets player sprite position, rotation, scale, and origin
	/// </summary>
	void init();

	/// <summary>
	/// sets movingSpeed to speed
	/// </summary>
	/// <param name="speed"></param>
	void updateSpeed(int speed);

	/// <summary>
	/// changes player texture based on selection number
	/// </summary>
	/// <param name="selectioNumber"></param>
	void chooseTexture(int selectioNumber);


	// plays m_gunsound
	void playGunSound();

private:
	// gunshot sounds
	sf::Sound m_gunSound;
	// buffer for the gunshot sounds
	sf::SoundBuffer m_gunSoundBuffer;

	// player texture sheet
	sf::Texture playerTextureSheet;

	/// <summary>
/// used to detect keyboard input and call some of the 4 movement functions below
/// </summary>
	void detectMovementInput();


	/// <summary>
	/// moves the player left and rotates
	/// </summary>
	void movementLeft();

	/// <summary>
	/// moves player right and rotates
	/// </summary>
	void movementRight();

	/// <summary>
	/// moves player up and rotates
	/// </summary>
	void movementUp();

	/// <summary>
	/// moves player down and rotates
	/// </summary>
	void movementDown();

	/// <summary>
	/// rotates player left
	/// </summary>
	void rotateLeft();

	/// <summary>
	/// rotates player right
	/// </summary>
	void rotateRight();

	/// <summary>
	///  lowers the players movement speed
	/// </summary>
	void sneak();

	// used to tell if player is shooting or not
	bool isPlayerShooting = false;
	// the rotation value of the player
	double rotation;
	// the speed the player can rotate
	double rotationSpeed;

	// speed the player can move
	float movingSpeed;



};

