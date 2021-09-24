#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class HUD
{
	const static int MAX_SPRITES = 3;
	sf::Sprite bulletHUDSprite[MAX_SPRITES];
	sf::Texture bulletHUDTexture;

	sf::Text ammoCountText;
	sf::Font m_font;


public:
	int numBulletsToDraw;
	void init(sf::Font& font);
	void draw(sf::RenderWindow& window, bool canBulletsBeDrawn);
	void update();
};

