#include "CollisionDetection.h"

bool CollisionDetection::player_ammoBox_Collision(sf::Sprite& playerSprite, sf::Sprite& ammoBoxSprite)
{
	if (playerSprite.getGlobalBounds().intersects(ammoBoxSprite.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionDetection::player_greenContainer_Collision(sf::Sprite& playerSprite, sf::Sprite& greenContainer)
{
	if (playerSprite.getGlobalBounds().intersects(greenContainer.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionDetection::player_obstacle_Collision(sf::Sprite& playerSprite, sf::RectangleShape obstacles)
{
	if (playerSprite.getGlobalBounds().intersects(obstacles.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionDetection::bullet_zombie_Collision(sf::Sprite& bulletSprite, sf::Sprite& zombieSprite)
{
	if (bulletSprite.getGlobalBounds().intersects(zombieSprite.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionDetection::player_zombie_Collision(sf::Sprite& playerSprite, sf::Sprite& zombieSprite)
{
	if (playerSprite.getGlobalBounds().intersects(zombieSprite.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionDetection::bullet_obstacle_collision(sf::Sprite& bulletSprite, sf::RectangleShape obstacles)
{
	//for (int i = 0; i < 10; i++)
	//{
		if (bulletSprite.getGlobalBounds().intersects(obstacles.getGlobalBounds()))
		{
			return true;
		}
		else
		{
			return false;
		}
	//}
}


