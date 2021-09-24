#include "Obstacle.h"
#include <iostream>

void Obstacle::init()
{
	if (!containerTexture.loadFromFile("./resources/images/BackgroundGreenContainer.png"))
	{
		std::cout << "error" << std::endl;
	}
	containerSprite.setTexture(containerTexture);
	containerSprite.setScale(0.8, 0.8);
	containerSprite.setOrigin(containerSprite.getGlobalBounds().width / 2, containerSprite.getGlobalBounds().height / 2);
	containerSprite.setPosition(800, 350);

	obstacles[0].setPosition(55, 235);
	obstacles[0].setSize(sf::Vector2f(285, 50));

	obstacles[1].setPosition(55, 780);
	obstacles[1].setSize(sf::Vector2f(570, 50));

	obstacles[2].setPosition(55, 235);
	obstacles[2].setSize(sf::Vector2f(55, 550));

	obstacles[3].setPosition(450, 235);
	obstacles[3].setSize(sf::Vector2f(180, 50));

	obstacles[4].setPosition(580, 235);
	obstacles[4].setSize(sf::Vector2f(55, 180));

	obstacles[5].setPosition(575, 525);
	obstacles[5].setSize(sf::Vector2f(50, 260));

	obstacles[6].setPosition(925, 130);
	obstacles[6].setSize(sf::Vector2f(100, 100));

	obstacles[7].setPosition(0, 0);
	obstacles[7].setSize(sf::Vector2f(10, ScreenSize::s_height));

	obstacles[8].setPosition(ScreenSize::s_width - 10, 0);
	obstacles[8].setSize(sf::Vector2f(10, ScreenSize::s_height));

	obstacles[9].setPosition(0, 0);
	obstacles[9].setSize(sf::Vector2f(ScreenSize::s_width, 10));

	obstacles[10].setPosition(0, ScreenSize::s_height - 10);
	obstacles[10].setSize(sf::Vector2f(ScreenSize::s_width, 10));

	obstacles[11].setPosition(775, 250);
	obstacles[11].setSize(sf::Vector2f(75, 250));

}

void Obstacle::draw(sf::RenderWindow& window)
{
	window.draw(containerSprite);
}

sf::RectangleShape Obstacle::getObstacles(int _i)
{
	return obstacles[_i];
}

sf::Vector2f Obstacle::getTopLeft(int obstacle_num)
{
	sf::Vector2f topLeft = obstacles[obstacle_num].getPosition();

	return topLeft;
}

sf::Vector2f Obstacle::getTopRight(int obstacle_num)
{
	float extraWidth = obstacles[obstacle_num].getSize().x;

	sf::Vector2f topRight = { obstacles[obstacle_num].getPosition().x + extraWidth , obstacles[obstacle_num].getPosition().y };

	return topRight;
}

sf::Vector2f Obstacle::getBottomLeft(int obstacle_num)
{
	float extraHeight = obstacles[obstacle_num].getSize().y;

	sf::Vector2f bottomLeft = { obstacles[obstacle_num].getPosition().x , obstacles[obstacle_num].getPosition().y + extraHeight };

	return bottomLeft;
}

sf::Vector2f Obstacle::getBottomRight(int obstacle_num)
{
	float extraWidth = obstacles[obstacle_num].getSize().x;

	float extraHeight = obstacles[obstacle_num].getSize().y;

	sf::Vector2f bottomRight = { obstacles[obstacle_num].getPosition().x + extraWidth ,  obstacles[obstacle_num].getPosition().y + extraHeight };

	return bottomRight;
}

sf::Sprite Obstacle::getContainerSprite()
{
	return containerSprite;
}

const int Obstacle::getMaxObstacles()
{
	return MAX_OBSTACLES;
}