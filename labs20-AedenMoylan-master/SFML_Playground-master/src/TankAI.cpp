#include "TankAi.h"

////////////////////////////////////////////////////////////
TankAi::TankAi(sf::Texture const & texture, std::vector<sf::Sprite> & wallSprites)
	: m_aiBehaviour(AiBehaviour::PATROL_MAP)
	, m_texture(texture)
	, m_wallSprites(wallSprites)
	, m_steering(0, 0)


{
	// Initialises the tank base and turret sprites.
	initSprites();
}

////////////////////////////////////////////////////////////
void TankAi::update(Tank const & playerTank, double dt)
{
	aiTankPosition = m_tankBase.getPosition();
	sf::Vector2f vectorToPlayer = seek(playerTank.getPosition());

	int rand1 = 1;
	int rand2 = 1;

	int randPlusOrMinus = 1;
	int rand2PlusOrMinus = 1;

	if (timer < 1000)
	{
		rand1 = rand() % 40 + 1;
		rand2 = rand() % 40 + 1;

		randPlusOrMinus = rand() % 2 + 1;
		rand2PlusOrMinus = rand() % 2 + 1;

		if (randPlusOrMinus == 2)
		{
			rand1 *= -1;
		}

		if (rand2PlusOrMinus == 2)
		{
			rand2 *= -1;
		}

		aiTankVector = (sf::Vector2f(rand1, rand2));
	}
	else if ( timer >= 1000)
	{
		timer = 0;
	}

	sf::Vector2f acceleration; // ADD THIS
	switch (m_aiBehaviour)
	{
	case AiBehaviour::SEEK_PLAYER:
		m_steering += thor::unitVector(vectorToPlayer);
		m_steering += collisionAvoidance();
		m_steering = MathUtility::truncate(m_steering, MAX_FORCE);
		acceleration = m_steering / MASS;  // ADD THIS
	//	m_velocity = MathUtility::truncate(m_velocity + m_steering, MAX_SPEED);
		m_velocity = MathUtility::truncate(m_velocity + acceleration, MAX_SPEED);

		break;
	case AiBehaviour::STOP:
		m_velocity = sf::Vector2f(0, 0);
		//motion->m_speed = 0;
		break;
	case AiBehaviour::PATROL_MAP:
		m_steering += thor::unitVector(aiTankVector);
		m_steering += collisionAvoidance();
		m_steering = MathUtility::truncate(m_steering, MAX_FORCE);
		acceleration = m_steering / MASS;  // ADD THIS
	//	m_velocity = MathUtility::truncate(m_velocity + m_steering, MAX_SPEED);
		m_velocity = MathUtility::truncate(m_velocity + acceleration, MAX_SPEED);

		break;
	default:
		break;
	}

	// Now we need to convert our velocity vector into a rotation angle between 0 and 359 degrees.
	// The m_velocity vector works like this: vector(1,0) is 0 degrees, while vector(0, 1) is 90 degrees.
	// So for example, 223 degrees would be a clockwise offset from 0 degrees (i.e. along x axis).
	// Note: we add 180 degrees below to convert the final angle into a range 0 to 359 instead of -PI to +PI
	auto dest = atan2(-1 * m_velocity.y, -1 * m_velocity.x) / thor::Pi * 180 + 180;

	auto currentRotation = m_rotation;

	// Find the shortest way to rotate towards the player (clockwise or anti-clockwise)
	if (std::round(currentRotation - dest) == 0.0)
	{
		m_steering.x = 0;
		m_steering.y = 0;
	}

	else if ((static_cast<int>(std::round(dest - currentRotation + 360))) % 360 < 180)
	{
		// rotate clockwise
		m_rotation = static_cast<int>((m_rotation) + 1) % 360;
	}
	else
	{
		// rotate anti-clockwise
		m_rotation = static_cast<int>((m_rotation) - 1) % 360;
	}


	if (thor::length(vectorToPlayer) < MAX_SEE_AHEAD)
	{
		m_aiBehaviour = AiBehaviour::STOP;
	}
	else
	{
		m_aiBehaviour = AiBehaviour::PATROL_MAP;
	}

	updateMovement(dt);

	setVisionCone(30);
}

////////////////////////////////////////////////////////////
void TankAi::render(sf::RenderWindow & window)
{
	// TODO: Don't draw if off-screen...
	window.draw(m_tankBase);
	window.draw(m_turret);
	window.draw(m_arrowLeft);
	window.draw(m_arrowRight);
	
}

////////////////////////////////////////////////////////////
void TankAi::init(sf::Vector2f position)
{
	m_tankBase.setPosition(position);
	m_turret.setPosition(position);

	for (sf::Sprite const wallSprite : m_wallSprites)
	{
		sf::CircleShape circle(wallSprite.getTextureRect().width * 1.5f);
		circle.setOrigin(circle.getRadius(), circle.getRadius());
		circle.setPosition(wallSprite.getPosition());
		m_obstacles.push_back(circle);
		
	}
}

////////////////////////////////////////////////////////////
sf::Vector2f TankAi::seek(sf::Vector2f playerPosition) const
{

	//sf::Vector2f aiMovingVector = aiTankPosition - playerPosition;
	//sf::Vector2f aiMovingVector = (playerPosition - aiTankPosition) ;

	//return aiMovingVector;

	if (m_aiBehaviour == AiBehaviour::PATROL_MAP)
	{
		return playerPosition - m_tankBase.getPosition();
	}

	if (m_aiBehaviour == AiBehaviour::SEEK_PLAYER)
	{
		return playerPosition - m_tankBase.getPosition();
	}

}

////////////////////////////////////////////////////////////
sf::Vector2f TankAi::collisionAvoidance()
{
	auto headingRadians = thor::toRadian(m_rotation);
	sf::Vector2f headingVector(std::cos(headingRadians) * MAX_SEE_AHEAD, std::sin(headingRadians) * MAX_SEE_AHEAD);
	m_ahead = m_tankBase.getPosition() + headingVector;
	m_halfAhead = m_tankBase.getPosition() + (headingVector * 0.5f);
	const sf::CircleShape mostThreatening = findMostThreateningObstacle();
	sf::Vector2f avoidance(0, 0);
	if (mostThreatening.getRadius() != 0.0)
	{		
		avoidance.x = m_ahead.x - mostThreatening.getPosition().x;
		avoidance.y = m_ahead.y - mostThreatening.getPosition().y;
		avoidance = thor::unitVector(avoidance);
		avoidance *= MAX_AVOID_FORCE;
	}
	else
	{
		avoidance *= 0.0f;
	}
	return avoidance;
}

////////////////////////////////////////////////////////////
const sf::CircleShape TankAi::findMostThreateningObstacle()
{
	//// The initialisation of mostThreatening is just a placeholder...
	//sf::CircleShape mostThreatening = m_obstacles.at(10);

	//float half{ 0.5f };
	//m_ahead = aiTankPosition + m_velocity * MAX_SEE_AHEAD;
	//m_halfAhead = aiTankPosition + m_velocity * MAX_SEE_AHEAD * half;
	//int i = 0;
	//for (sf::Sprite const wallSprite : m_wallSprites)

	//{
	//	MathUtility::lineIntersectsCircle(m_ahead, m_halfAhead, m_obstacles[0]);
	//	i++;
	//	

	//}

	//return mostThreatening;

	// The initialisation of mostThreatening is just a placeholder...
	sf::CircleShape mostThreatening(0, 0);

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		sf::CircleShape obstacle = m_obstacles.at(i);

		bool collision = MathUtility::lineIntersectsCircle(m_ahead, m_halfAhead, obstacle);

		if (MathUtility::distance(m_ahead, obstacle.getPosition()) < 0.95 * obstacle.getRadius() ||
			MathUtility::distance(m_ahead, obstacle.getPosition()) > 1.05 * obstacle.getRadius())
		{
			// "position" is the character's current position
			if (collision && (mostThreatening.getPosition() == sf::Vector2f(0, 0) || MathUtility::distance(m_tankBase.getPosition(), obstacle.getPosition()) < MathUtility::distance(m_tankBase.getPosition(), mostThreatening.getPosition())))
			{
				mostThreatening = obstacle;
			}

		}

	}
	return mostThreatening;

}

////////////////////////////////////////////////////////////
void TankAi::initSprites()
{
	// Initialise the tank base
	m_tankBase.setTexture(m_texture);
	sf::IntRect baseRect(103, 43, 79, 43);
	m_tankBase.setTextureRect(baseRect);
	m_tankBase.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);

	// Initialise the turret
	m_turret.setTexture(m_texture);
	sf::IntRect turretRect(122, 1, 83, 31);
	m_turret.setTextureRect(turretRect);
	m_turret.setOrigin(turretRect.width / 3.0, turretRect.height / 2.0);
}


////////////////////////////////////////////////////////////
void TankAi::updateMovement(double dt)
{
	double speed = thor::length(m_velocity);
	sf::Vector2f newPos(m_tankBase.getPosition().x + std::cos(MathUtility::DEG_TO_RAD  * m_rotation) * speed * (dt / 1000),
		m_tankBase.getPosition().y + std::sin(MathUtility::DEG_TO_RAD  * m_rotation) * speed * (dt / 1000));
	m_tankBase.setPosition(newPos.x, newPos.y);
	m_tankBase.setRotation(m_rotation);
	m_turret.setPosition(m_tankBase.getPosition());
	m_turret.setRotation(m_rotation);
}

bool TankAi::collidesWithPlayer(Tank const& playerTank) const
{
	// Checks if the AI tank has collided with the player tank.
	if (CollisionDetector::collision(m_turret, playerTank.getTurret()) ||
		CollisionDetector::collision(m_tankBase, playerTank.getBase()))
	{
		return true;
	}
	return false;
}

sf::Sprite TankAi::getBase()
{
	return m_tankBase;
}

void TankAi::applyDamage(int t_damageAmount)
{
	tankHealth -= t_damageAmount;


}

sf::Sprite TankAi::getTankBase()
{

	return m_tankBase;
}

void TankAi::setVisionCone(float t_angle)
{
	m_visionConeLeft = m_turret.getPosition();
	m_visionConeRight = m_turret.getPosition();

	// Setup the arrow visualisation
	m_arrowLeft.setStyle(thor::Arrow::Style::Forward);
	m_arrowLeft.setColor(sf::Color::Green);
	m_arrowLeft.setPosition(m_visionConeLeft);
	m_arrowRight.setStyle(thor::Arrow::Style::Line);
	m_arrowRight.setColor(sf::Color::Green);
	m_arrowRight.setPosition(m_visionConeRight);

	m_arrowLeft.setRotation(m_turret.getRotation());
	m_arrowRight.setRotation(m_turret.getRotation());
	m_arrowLeft.setDirection(VISION_CONE_LENGTH * thor::rotatedVector(m_visionConeDir, -t_angle));
	m_arrowRight.setDirection(VISION_CONE_LENGTH * thor::rotatedVector(m_visionConeDir, t_angle));


}

sf::Vector2f TankAi::getPosition() const
{
	return m_tankBase.getPosition();
}