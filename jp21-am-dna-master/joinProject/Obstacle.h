#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"

class Obstacle
{
	/// <summary>
	/// sprite for the container
	/// </summary>
	sf::Sprite containerSprite;

	/// <summary>
	/// texture for the container
	/// </summary>
	sf::Texture containerTexture;

	/// <summary>
	/// the max number of obstacles
	/// </summary>
	const static int MAX_OBSTACLES = 12;

public:

	/// <summary>
	/// initialises the obstacles. extracts textures, scales sprites, and sets size and position of obstacles
	/// </summary>
	void init();

	/// <summary>
	/// draws the container sprite using the passed sf::RenderWindow
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);

	/// <summary>
	/// an array of all the obstacles
	/// </summary>
	sf::RectangleShape obstacles[MAX_OBSTACLES];

	/// <summary>
	/// returns top left position of the obstacle. obstacle_num determines which obstacle this function is used for
	/// </summary>
	/// <param name="obstacle_num"></param>
	/// <returns></returns>
	sf::Vector2f getTopLeft(int obstacle_num);

	/// <summary>
	/// returns top right position of the obstacle. obstacle_num determines which obstacle this function is used for
	/// </summary>
	/// <param name="obstacle_num"></param>
	/// <returns></returns>
	sf::Vector2f getTopRight(int obstacle_num);

	/// <summary>
	/// returns bottom left position of the obstacle. obstacle_num determines which obstacle this function is used for
	/// </summary>
	/// <param name="obstacle_num"></param>
	/// <returns></returns>
	sf::Vector2f getBottomLeft(int obstacle_num);

	/// <summary>
	/// returns bottom right position of the obstacle. obstacle_num determines which obstacle this function is used for
	/// </summary>
	/// <param name="obstacle_num"></param>
	/// <returns></returns>
	sf::Vector2f getBottomRight(int obstacle_num);

	/// <summary>
	/// returns the container sprite
	/// </summary>
	/// <returns></returns>
	sf::Sprite getContainerSprite();

	/// <summary>
	/// returns the rectangle shape obstacle. returns obstacle number based on _i
	/// </summary>
	/// <param name="_i"></param>
	/// <returns></returns>
	sf::RectangleShape getObstacles(int _i);

	/// <summary>
	/// returns MAX_OBSTACLES
	/// </summary>
	/// <returns></returns>
	const static int getMaxObstacles();
};
