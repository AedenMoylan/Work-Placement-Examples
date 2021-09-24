
#pragma once

#include "Animation.h"


class Zombie
{
	/// <summary>
	/// zombie health
	/// </summary>
	int health;

	/// <summary>
	/// 
	/// </summary>
	const int HEALTH_REDUCTION_AMOUNT = 10;
	sf::Vector2f position;

public:
	enum class ZombieAnimationState { walk, run, jump, idle };
	ZombieAnimationState animationState = ZombieAnimationState::walk;
	Animation animations[5];
	AnimationSheet animSheet;
	sf::Sprite& spriteSheet;

	/// <summary>
	/// initialises zombie variables and calls initAnimationDate()
	/// </summary>
	void init();

	/// <summary>
	/// texture sheet of zombie 
	/// </summary>
	sf::Texture zombieTextureSheet;
	/// <summary>
	/// spriteSheet of zombie
	/// </summary>
	sf::Sprite zombieSpriteSheet;

	Zombie(sf::Sprite& spheet) : spriteSheet(spheet)
	{

	}

	/// <summary>
	/// initializes zombie data needed to execute animations using zombie animation states
	/// </summary>
	void InitAnimationData();

	/// <summary>
	/// sets the zombie animation state and calls startAnimation() which starts the animation 
	/// </summary>
	/// <param name="_animationState"></param>
	void startAnimation(ZombieAnimationState _animationState);

	/// <summary>
	/// passes the render window to draw the zombie sprites. Called in Game.cpp
	/// </summary>
	/// <param name="win"></param>
	void Draw(sf::RenderWindow& win);

	/// <summary>
	/// returns zombie health
	/// </summary>
	/// <returns></returns>
	int getHealth();

	/// <summary>
	/// reduces zombie health by HEALTH_REDUCTION_AMOUNT. called when the bullet collides with zombie
	/// </summary>
	void reduceHealth();

	/// <summary>
	/// returns zombie position
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// moves zombie in the direction of _targetLocation and also sets the player position to the moved amount
	/// </summary>
	/// <param name="_targetLocation"></param>
	void move(sf::Vector2f _targetLocation);
};

