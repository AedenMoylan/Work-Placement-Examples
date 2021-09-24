#pragma once
#include "Player.h"
#include "Zombie.h"
#include "AmmoBox.h"
#include "Bullet.h"

class CollisionDetection
{
public:
	// these functions detect collisions with the sprites and rect shapes passed to it and returns a bool to determine is a collision has occured
	bool player_ammoBox_Collision(sf::Sprite& playerSprite, sf::Sprite& ammoBoxSprite);
	bool player_greenContainer_Collision(sf::Sprite& playerSprite, sf::Sprite& greenContainer);
	bool player_obstacle_Collision(sf::Sprite& playerSprite, sf::RectangleShape obstacles);
	bool bullet_zombie_Collision(sf::Sprite& bulletSprite, sf::Sprite& zombieSprite);
	bool player_zombie_Collision(sf::Sprite& playerSprite, sf::Sprite& zombieSprite);
	bool bullet_obstacle_collision(sf::Sprite& bulletSprite, sf::RectangleShape obstacles);
};