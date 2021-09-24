#include "Bullet.h"

void Bullet::init()
{
	if (!bulletTexture.loadFromFile("./resources/images/bullet.png"))
	{
		std::cout << "error" << std::endl;
	}

	bulletSprite.setScale(0.05, 0.05);
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	bulletSprite.setTexture(bulletTexture);

	bulletSprite.setPosition(50000, 50000);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(bulletSprite);
}

void Bullet::setBulletPosition(sf::Sprite t_playerSprite)
{
	bulletPosition = sf::Vector2f{ t_playerSprite.getPosition()};
}

void Bullet::update()
{
	moveBullet();
}

void Bullet::setRotation(sf::Sprite t_playerSprite)
{
	bulletSprite.setRotation(t_playerSprite.getRotation());
}

void Bullet::moveBullet()
{
	counter += 10;
	sf::Vector2f tempPosition = bulletPosition;
	sf::Vector2f bulletPosition(tempPosition.x + std::cos(MathUtility::DEG_TO_RAD * bulletSprite.getRotation()) * speed * (counter / 2),
	tempPosition.y + std::sin(MathUtility::DEG_TO_RAD * bulletSprite.getRotation()) * speed * (counter / 2));
	bulletSprite.setPosition(bulletPosition.x, bulletPosition.y);
}

void Bullet::despawnBullet()
{
	bulletPosition = { 50000, 50000 };
}

int Bullet::getCounter()
{
	return counter;
}

void Bullet::setIsBulletActive(bool _i)
{
	isBulletActive = _i;
}

void Bullet::setCounter(int _i)
{
	counter = _i;
}