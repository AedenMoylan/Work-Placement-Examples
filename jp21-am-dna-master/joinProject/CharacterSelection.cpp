#include "CharacterSelection.h"

void CharacterSelection::setupSprites(sf::Font& font)
{
	if (!grayShirtTexture.loadFromFile("./resources/images/playerSpriteSheet.png"))
	{
		std::cout << "gray problem" << std::endl;
	}

	grayShirtSprite.setTexture(grayShirtTexture);

	if (!blueShirtTexture.loadFromFile("./resources/images/playerSpriteSheet_blue.png"))
	{
		std::cout << "blue problem" << std::endl;
	}

	blueShirtSprite.setTexture(blueShirtTexture);

	if (!brownShirtTexture.loadFromFile("./resources/images/playerSpriteSheet_brown.png"))
	{
		std::cout << "brown problem" << std::endl;
	}

	brownShirtSprite.setTexture(brownShirtTexture);

	blueShirtSprite.setScale(scaleAmount, scaleAmount);
	blueShirtSprite.setPosition(40, 200);

	brownShirtSprite.setScale(5, 5);
	brownShirtSprite.setPosition(400, 200);

	grayShirtSprite.setScale(5, 5);
	grayShirtSprite.setPosition(760, 200);

	//================================================================================ below is for the buttons
	m_topOffset = 650;
	m_horizontalSpacing = 360;
	m_buttonWidth = 200;
	m_leftOffset = 50;
	m_buttonHeight = 70;
	int textDropOffset = 21;
	sf::String m_menuTexts[] = { "BLUE", "BROWN", "GRAY" };
	m_font = font;

	/// display error if button.png doesnt load properly
	if (!m_buttonTexture.loadFromFile("./resources/images/button.png"))
	{
		std::cout << "error with button file";
	}

	/// for loop to setup menu buttons in an array
	/// keeps them in a centre nicely laid out
	/// scales them to texture size so they look to scale
	/// 
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset + m_horizontalSpacing * i, m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		// sets font up for the array of text shapes that display over the buttons
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setFillColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(22);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_horizontalSpacing * i + m_leftOffset + textOffset, m_topOffset + textDropOffset);
	}

}

void CharacterSelection::draw(sf::RenderWindow& window)
{
	window.draw(blueShirtSprite);
	window.draw(brownShirtSprite);
	window.draw(grayShirtSprite);

	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
}

void CharacterSelection::update(sf::Window& window)
{
	if (scaleAmount >= 5.2)
	{
		areSpritesScalingUp = false;
	}

	if (scaleAmount <= 4.8)
	{
		areSpritesScalingUp = true;
	}

	if (areSpritesScalingUp == true)
	{
		scaleAmount = scaleAmount * SCALE_SPEED;
	}

	if (areSpritesScalingUp == false)
	{
		scaleAmount = scaleAmount * SCALE_SPEED_DECREASE;
	}

	blueShirtSprite.setScale(scaleAmount, scaleAmount);
	brownShirtSprite.setScale(scaleAmount, scaleAmount);
	grayShirtSprite.setScale(scaleAmount, scaleAmount);

	selectionNumber = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.y > m_topOffset && mouseLocation.y < m_topOffset + m_buttonHeight)
		{
			if (mouseLocation.x > m_leftOffset && mouseLocation.y && mouseLocation.x < m_leftOffset + m_buttonWidth)
			{
				selectionNumber = 1;
			}
			if (mouseLocation.x > m_leftOffset + m_horizontalSpacing && mouseLocation.x < m_leftOffset + m_horizontalSpacing + m_buttonWidth)
			{
				selectionNumber = 2;
			}

			if (mouseLocation.x > m_leftOffset + m_horizontalSpacing * 2 && mouseLocation.x < m_leftOffset + m_horizontalSpacing * 2 + m_buttonWidth)
			{
				selectionNumber = 3;
			}
		}
	}
}

int CharacterSelection::getSelectionNumber()
{
	return selectionNumber;
}