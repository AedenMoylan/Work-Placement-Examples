#include "Background.h"


void Background::backgroundInit()
{
	if (!backgroundTexture.loadFromFile("./resources/images/newBackground.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!victoryBackgroundTexture.loadFromFile("./resources/images/victoryBackgroundSprite.jpeg"))
	{
		std::cout << "error" << std::endl;
	}

	if (!loseBackgroundTexture.loadFromFile("./resources/images/loseBackgroundSprite.jpg"))
	{
		std::cout << "error" << std::endl;
	}

	backgroundSprite.setTexture(backgroundTexture);

	victoryBackgroundSprite.setTexture(victoryBackgroundTexture);

	loseBackgroundSprite.setTexture(loseBackgroundTexture);

	backgroundSprite.setScale(1.2, 1.2);

	victoryBackgroundSprite.setScale(0.55, 0.7);

	loseBackgroundSprite.setPosition(-100, -100);

	loseBackgroundSprite.setScale(0.3, 0.4);

}

void Background::draw(sf::RenderWindow& win)
{
	win.draw(backgroundSprite);
}

void Background::drawVictory(sf::RenderWindow& win)
{
	win.draw(victoryBackgroundSprite);
}

void Background::drawLose(sf::RenderWindow& win)
{
	win.draw(loseBackgroundSprite);
}