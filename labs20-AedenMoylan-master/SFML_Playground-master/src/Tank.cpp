
#include "Tank.h"
#include <iostream>
Tank::Tank(sf::Texture const& texture, std::vector<sf::Sprite>& t_wallSprites)
	: m_texture(texture)
	, m_wallSprites(t_wallSprites)
{
	srand(time(NULL));
	initSprites();
	tankStartPosition();


}



void Tank::update(double dt, std::function<void(int)>& t_funcApplyDamage, sf::Sprite t_tankBase)
{
	if (m_fireRequested == true)
	{
		m_shootTimer -= dt;
		if (m_shootTimer <= 0)
		{
			m_shootTimer = s_TIME_BETWEEN_SHOTS;
			m_fireRequested = false;
		}
	}

	m_pool.update(dt, m_wallSprites, t_funcApplyDamage, t_tankBase);

	float rotateInRadians = (MathUtility::DEG_TO_RAD * m_tankRotation);

	float newXPosition = m_tankBase.getPosition().x + cos(rotateInRadians) * m_speed * (dt / 1000);
	float newYPosition = m_tankBase.getPosition().y + sin(rotateInRadians) * m_speed * (dt / 1000);


	// increases the variable bulletShootTimer by 1
	bulletTimer();
	
	if (canBulletShoot == true)
		{
			if (isBulletFired)
			{

				isBulletFired = false;
				canBulletShoot = false;
				double rotation = m_turret.getRotation();
				sf::Vector2f turretPos = m_turret.getPosition();

				m_startPoint = sf::Vector2f(
					turretPos.x + 1 * std::cos(rotation * MathUtility::DEG_TO_RAD),
					turretPos.y + 1 * std::sin(rotation * MathUtility::DEG_TO_RAD)
				);
				// set position of bullet to m_startPoint 
				m_bullet.setPosition(m_startPoint);
				m_startPoint = thor::unitVector(m_startPoint - m_turret.getPosition());
			}

		}

		// moves the bullet in the direction it is supposed to
	m_bullet.move(m_startPoint.x * PROJECTILE_SPEED * (dt / 1000),
		m_startPoint.y * PROJECTILE_SPEED * (dt / 1000));
	// sets tank position and rotation
	m_tankBase.setPosition(newXPosition, newYPosition);
	m_tankBase.setRotation(m_tankRotation);
	// sets turret position and rotation
	m_turret.setPosition(m_tankBase.getPosition());
	m_turret.setRotation(m_turretRotation);

	// stops speed from going above 50 or below -50
	m_speed = std::clamp(m_speed, -20.0, 50.0);
	// slows down tank
	m_speed *= 0.99;
	// stops tank if speed is low
	if (m_speed < -0.01 && m_speed > -1)
	{
		m_speed = 0;
	}

	if (m_speed < 1 && m_speed > 0.01)
	{
		m_speed = 0;
	}

		// changes the tank volume depending in tank speed
	if (m_speed > 4 && m_speed < 51 )
	{
		
		m_drivingSound.setVolume(10);
	}

	if (m_speed < -4 && m_speed > -51)
	{
		
		m_drivingSound.setVolume(15);
	}

	if (m_speed >= -4 && m_speed <= 4)
	{
		
		m_drivingSound.setVolume(3);
	}


	// detects collisions and deflects tank and turret from wall if they collided
	if (checkWallCollision())
	{
		deflect();
	}



}

void Tank::render(sf::RenderWindow& window)
{
	m_pool.render(window);
	window.draw(m_tankBase);
	window.draw(m_bullet);
	window.draw(m_turret);
}


void Tank::initSprites()
{
	// Initialise the tank base
	m_tankBase.setTexture(m_texture);
	sf::IntRect baseRect(2, 43, 79, 43);
	m_tankBase.setTextureRect(baseRect);
	m_tankBase.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);

	// Initialise the turret
	m_turret.setTexture(m_texture);
	sf::IntRect turretRect(19, 1, 83, 31);
	m_turret.setTextureRect(turretRect);
	m_turret.setOrigin(turretRect.width / 3.0, turretRect.height / 2.0);

	// initialise the bullet sprite
	m_bullet.setTexture(m_texture);
	sf::IntRect bulletRect(8, 177, 6, 9);
	m_bullet.setTextureRect(bulletRect);
	m_bullet.setOrigin(bulletRect.width / 2, bulletRect.height / 2);

	if (!m_shotBuffer.loadFromFile("./resources/audio/gunSound.wav"))
	{
		std::string s("Error loading textureeeeeee");
		throw std::exception(s.c_str());
	}

	if (!m_tankDrivingBuffer.loadFromFile("./resources/audio/tankMovingSound.wav"))
	{
		std::string s("Error loading textureeeeeee");
		throw std::exception(s.c_str());
	}
	
	// set buffer or shooting sound and sriving sound
	m_drivingSound.setBuffer(m_tankDrivingBuffer);

	m_shootingSound.setBuffer(m_shotBuffer);
	// plays driving sound
	m_drivingSound.play();
}

void Tank::setPosition()
{
	m_tankBase.setPosition(m_position);
	m_turret.setPosition(m_position);
}

void Tank::increaseSpeed()
{
	if (m_speed > 0)
	{
		// used to detect collisions to the walls
		speedPositive = true;
		speedNegative = false;
	}

	m_speed += 2;
	if (m_speed < 100.0)
	{
		m_speed += 1;
	}
}

////////////////////////////////////////////////////////////
void Tank::decreaseSpeed()
{
	if (m_speed < 0)
	{
		// used to detect collisions to the walls
		speedPositive = false;
		speedNegative = true;
	}

	m_speed -= 2;
	if (m_speed > -100.0)
	{
		m_speed -= 1;
	}
}

// rotate turret clockwise
void Tank::increaseTurretRotation()
{
	m_previousTurretRotation = m_turretRotation; 

	m_turretRotation += turretRotationSpeed;
	if (m_turretRotation == 360.0)
	{
		m_turretRotation = 0;
	}
}
// rotate turret anti clockwise
void Tank::decreaseTurretRotation()
{
	m_previousTurretRotation = m_turretRotation; 

	m_turretRotation -= turretRotationSpeed;

	if (m_turretRotation == 360.0)
	{
		m_turretRotation = 0;
	}
}
////////////////////////////////////////////////////////////
/// rotate tank and turret clockwise at the same time
void Tank::increaseRotation()
{
	m_previousRotation = m_tankRotation; 

	m_tankRotation += tankRotationSpeed;
	increaseTurretRotation();

	if (m_tankRotation == 360.0)
	{
		m_tankRotation = 0;
	}
}

////////////////////////////////////////////////////////////
/// rotates tank and turret at the same time anti clockwise
void Tank::decreaseRotation()
{
	m_previousRotation = m_tankRotation; 

	m_tankRotation -= tankRotationSpeed;
	decreaseTurretRotation();

	if (m_tankRotation == 0.0)
	{
		m_tankRotation = 359.0;
	}
}

// sets turret rotation to the tanks rotation value to center it
void Tank::centerTurret()
{
	m_turretRotation = m_tankRotation;
}


void Tank::handleKeyInput()
{
	// check if the event is a a mouse button release
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		increaseSpeed();
		// move forward/ increase speed
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		increaseRotation();
		// rotate tank clockwise
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		decreaseSpeed();
		// slow down/ move backwards
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		decreaseRotation();
		// rotate tank anticlockwise
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		decreaseTurretRotation();
		// rotate turret anticlockwise
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		increaseTurretRotation();
		// rotate turret clockwise
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		centerTurret();
		// recenter turret
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_fireRequested == false)
	{
		//// plays shooting sound
		//m_shootingSound.play();
		////checks if bullet collided with wall
		//didBulletCollide == false;
		//// turns this bool to true which signifies that the bullet is fired
		//isBulletFired = true;
		//// rotates the bullet to match the turret 
		//shotsFired++;
		//// rotates bullet to match tank
		requestFire();

		//findBulletRotation();
	}
}

// checks collisions between sprites. teleports bullet out of bounds if it touches a wall
bool Tank::checkWallCollision()
{
	for (sf::Sprite const& sprite : m_wallSprites)
	{
		// Checks if either the tank base or turret has collided with the current wall sprite.
		if (CollisionDetector::collision(m_turret, sprite) ||
			CollisionDetector::collision(m_tankBase, sprite))
		{
			return true;
		}
		// spawns bullet off screen if collided
		if ((CollisionDetector::collision(m_bullet, sprite)))
		{
			m_bullet.setPosition(50000, 50000);
			
		}
	}
	return false;
}

void Tank::deflect()
{
	// In case tank was rotating.
	adjustRotation();

	
	// If tank was moving.
	if (m_speed != 0)
	{
		// Temporarily disable turret rotations on collision.
		m_enableRotation = false;
		// Back up to position in previous frame.
		
		m_previousPosition = m_tankBase.getPosition();
		m_tankBase.setPosition(m_previousPosition);
		// Apply small force in opposite direction of travel.

		if ( speedNegative == true && speedPositive == false)
		{
			m_speed = 8;
		}
		else if (speedPositive == true && speedNegative == false)
		{
			m_speed = -8;
		}
	}
}

void Tank::adjustRotation()
{
	// If tank was rotating...
	if (m_tankRotation != m_previousRotation)
	{
		// Work out which direction to rotate the tank base post-collision.
		if (m_tankRotation > m_previousRotation)
		{
			m_tankRotation = m_previousRotation - 1;
		}
		else
		{
			m_tankRotation = m_previousRotation + 1;
		}
	}
	// If turret was rotating while tank was moving
	if (m_turretRotation != m_previousTurretRotation)
	{
		// Set the turret rotation back to it's pre-collision value.
		m_turretRotation = m_previousTurretRotation;
	}
}

// rotates the bullet to match the direction the turret is facing
void Tank::findBulletRotation()
{

		// the bullet only matches the position of the turret rotation if it is reduced by 90
		m_bullet.setRotation(m_turretRotation - 90);
	
}

// increases bullet shoot timer. resets to 0 after it reaches 60. canBulletShoot == false when below 60 and true when above 60. 
// used to add a second gap between shooting
void Tank::bulletTimer()
{
	if (canBulletShoot == false && bulletShootTimer <= 60)
	{
		bulletShootTimer++;
	}
	if (bulletShootTimer > 60)
	{
		bulletShootTimer = 0;
		canBulletShoot = true;
	}

}

sf::Sprite Tank::getBulletBody()
{
	return m_bullet;
}

// sets the starting spawn location of the tank to be one of the 4 corners
void Tank::tankStartPosition()
{
	sf::Vector2f corner1 = sf::Vector2f(100, 100);
	sf::Vector2f corner2 = sf::Vector2f(ScreenSize::s_width - 100, 100);
	sf::Vector2f corner3 = sf::Vector2f(100, ScreenSize::s_height - 100);
	sf::Vector2f corner4 = sf::Vector2f(ScreenSize::s_width - 100, ScreenSize::s_height - 100);

	sf::Vector2f randomSpawnNumber;
	int randNum = rand() % 4 + 1;


	switch (randNum)
	{
	case 1:
		randomSpawnNumber = corner1;
		break;
	case 2:
		randomSpawnNumber = corner2;
		break;
	case 3:
		randomSpawnNumber = corner3;
		break;
	case 4:
		randomSpawnNumber = corner4;
		break;
	}

	m_tankBase.setPosition(randomSpawnNumber);
}

sf::Vector2f Tank::getPosition() const
{
	return m_tankBase.getPosition();
}

////////////////////////////////////////////////////////////
void Tank::requestFire()
{
	m_fireRequested = true;
	if (m_shootTimer == s_TIME_BETWEEN_SHOTS)
	{
		sf::Vector2f tipOfTurret(m_turret.getPosition().x + 2.0f, m_turret.getPosition().y);
		tipOfTurret.x += std::cos(MathUtility::DEG_TO_RAD * m_turret.getRotation()) * ((m_turret.getLocalBounds().top + m_turret.getLocalBounds().height) * 1.7f);
		tipOfTurret.y += std::sin(MathUtility::DEG_TO_RAD * m_turret.getRotation()) * ((m_turret.getLocalBounds().top + m_turret.getLocalBounds().height) * 1.7f);
		m_pool.create(m_texture, tipOfTurret.x, tipOfTurret.y, m_turret.getRotation());

        
	}
}

sf::Sprite Tank::getBase() const
{
	return m_tankBase;
}

sf::Sprite Tank::getTurret() const
{
	return m_turret;
}

