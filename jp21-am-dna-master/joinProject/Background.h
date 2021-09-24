#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenSize.h"

class Background
{

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	sf::Sprite victoryBackgroundSprite;
	sf::Texture victoryBackgroundTexture;

	sf::Sprite loseBackgroundSprite;
	sf::Texture loseBackgroundTexture;

public:

	/// <summary>
	/// loads the textures, sets scale, position, and sets the textures
	/// </summary>
	void backgroundInit();



	void draw(sf::RenderWindow& win);
	void drawVictory(sf::RenderWindow& win);
	void drawLose(sf::RenderWindow& win);
};