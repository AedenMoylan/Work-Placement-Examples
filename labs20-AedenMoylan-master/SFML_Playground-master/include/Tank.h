
#pragma once
#include <SFML/Graphics.hpp>
#include <MathUtility.h>
#include <algorithm>
#include "CollisionDetector.h"
#include <Thor/Time.hpp>
#include "ScreenSize.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "ProjectilePool.h"

/// <summary>
/// @brief A simple tank controller.
/// 
/// This class will manage all tank movement and rotations.
/// </summary>
class Tank
{
public:

	ProjectilePool m_pool;

	Tank(sf::Texture const& texture, std::vector<sf::Sprite> &m_wallSprites);
	void update(double dt, std::function<void(int)>& t_funcApplyDamage, sf::Sprite t_tankBase);
	void render(sf::RenderWindow& window);
	void increaseSpeed();
	void handleKeyInput();

	/// <summary>
	/// @brief Decreases the speed by 1, min speed is capped at -100.
	/// 
	/// </summary>
	void decreaseSpeed();

	/// <summary>
	/// @brief Increases the rotation by 1 degree, wraps to 0 degrees after 359. also increases turret rotation by same amount
	/// 
	/// </summary>
	void increaseRotation();

	/// <summary>
	/// @brief Decreases the rotation by 1 degree, wraps to 359 degrees after 0. also decreases turret rotation by same amount
	/// 
	/// </summary>
	void decreaseRotation();

	// increases the turret rotation by 1 degree, wraps to 0 degrees after 359.
	void increaseTurretRotation();
	// decreases the turret rotation by 1 degree, wraps to 0 degrees after 359.
	void decreaseTurretRotation();
	// makes the bullet rotation = the turret rotation. will be called when the bullet is fired
	void findBulletRotation();

	// centers turret when the c key is pressed
	void centerTurret();

	/// <summary>
/// @brief Checks for collisions between the tank and the walls.
/// 
/// </summary>
/// <returns>True if collision detected between tank and wall.</returns>
	bool checkWallCollision();

	// bounces the tank off the wall
	void deflect();

	// increases bullet shoot timer. resets to 0 after it reaches 60. canBulletShoot == false when below 60 and true when above 60. 
// used to add a second gap between shooting
	void bulletTimer();

	// sets the starting spawn location of the tank to be one of the 4 corners
	void tankStartPosition();

	/// <summary>
/// @brief Generates a request to fire a projectile.
/// A projectile will be fired from the tip of the turret only if time limit between shots
///  has expired. Fire requests are not queued.
/// </summary>
	void requestFire();

	/// <summary>
/// @brief Reads the player tank position.
/// <returns>The tank base position.</returns>
/// </summary>
	sf::Vector2f getPosition() const;

	// returns the bullet sprite
	sf::Sprite getBulletBody();

	// returns tank base
	sf::Sprite getBase() const;

	// returns turret sprite
	sf::Sprite getTurret() const;

	// number of bullets fired
	float shotsFired = { 0.0 };

	// The delay time between shots in milliseconds.
	static int const s_TIME_BETWEEN_SHOTS{ 800 };

	bool m_fireRequested = false;

	int m_shootTimer = 60;

	// sound and buffer for when the bullet is shot
	sf::Sound m_shootingSound;
	sf::SoundBuffer m_shotBuffer;
	// sound and buffer for when the tank moves
	sf::Sound m_drivingSound;
	sf::SoundBuffer m_tankDrivingBuffer;

	void setPosition();
	double m_speed = 0.0;
	sf::Sprite m_tankBase;
private:
	//speed of the bullet
	static constexpr float PROJECTILE_SPEED{ 1000.0f };

	// Where to draw the projectile.
	sf::Vector2f m_startPoint;


	// used in functions increaseSpeed and decrease speed to tell when the tank is moving forward or backwards
	bool speedPositive;
	bool speedNegative;
	// used to keep track of when a second has passed
	int bulletShootTimer = 60;
	// the speed the turret can rotate
	float turretRotationSpeed{ 1 };
	// the speed the tank can rotate
	float tankRotationSpeed{ 1 };

	// Where to draw the projectile.
	//sf::Vector2f m_startPoint;
	bool canBulletShoot = true;
	// used to detect when the space bar button yo fire a bullet is pressed
	bool isBulletFired = false;

	void adjustRotation();
	// true if bullet collision occurs
	bool didBulletCollide = false;
	// The tank speed.
	// tank starting position
	sf::Vector2f m_position{ 500.0f, 300.0f };
	// previous position of the tank before it hits an obstable
	sf::Vector2f m_previousPosition;
	// The current rotation as applied to tank base.
	double m_tankRotation{ 0.0 };
	// same but with turret
	double m_turretRotation{ 0.0 };
	// bullet rotation amount
	double m_bulletRotation{ 0 };



	// enables rotation if tank isn't colliding with object
	bool m_enableRotation = true;

	// stores the previous rotation of the turret and tank
	double m_previousRotation;
	double m_previousTurretRotation;
	// sets starting point of tank
	// initialising the sprites
	void initSprites();
	// sprite of tank
	// sprite of turret
	sf::Sprite m_turret;
	// sprite of bullet
	sf::Sprite m_bullet;

	// texture of tankbase
	sf::Texture const& m_texture;
	// std ::vector sprite of wall sprites
	std::vector<sf::Sprite>& m_wallSprites;
};
