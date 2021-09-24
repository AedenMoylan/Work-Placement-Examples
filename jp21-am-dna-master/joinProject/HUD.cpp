#include "HUD.h"

void HUD::init(sf::Font& font)
{
	if (!bulletHUDTexture.loadFromFile("./resources/images/HUDBullet.png"))
	{
		std::cout << "error" << std::endl;
	}

	for (int i = 0; i < MAX_SPRITES; i++)
	{


		bulletHUDSprite[i].setTexture(bulletHUDTexture);

		bulletHUDSprite[i].setScale(0.1, 0.1);

		bulletHUDSprite[i].setPosition((i+ 1) * 50 + 770, 685);
	}

	m_font = font;

	ammoCountText.setFont(m_font);
	ammoCountText.setString("Ammo: ");
	ammoCountText.setPosition(700, 700);
	ammoCountText.setCharacterSize(30);
	ammoCountText.setFillColor(sf::Color::Red);

	numBulletsToDraw = 4;
}

void HUD::draw(sf::RenderWindow& window, bool ammoCollected)
{
	if (ammoCollected == true)
	{
		for (int i = 0; i < numBulletsToDraw; i++)
		{
			window.draw(bulletHUDSprite[i]);
		}
	}

	window.draw(ammoCountText);
}

void HUD::update()
{

}