
#include "Menu.h"


void Menu::initialise(sf::Font& font)
{
	m_topOffset = 250;
	m_verticalSpacing = 100;
	m_buttonWidth = 400;
	m_leftOffset = (1050 - m_buttonWidth) / 2;
	m_buttonHeight = 70;
	int textDropOffset = 21;
	sf::String m_menuTexts[] = { "Play", "Character selection ", "option 3", "Exit" };
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
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		// sets font up for the array of text shapes that display over the buttons
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setFillColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(22);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing * i + m_topOffset + textDropOffset);
	}

	if (!menuBgTexture.loadFromFile("./resources/images/menuBg.png"))
	{
		std::cout << "error with button file";
	}


	if (!m_menuMusicBuffer.loadFromFile("./resources/audio/menuBackground.wav"))
	{
		std::string s("Error loading textureeeeeee");
		throw std::exception(s.c_str());
	}

	m_menuMusic.setBuffer(m_menuMusicBuffer);

	playMusic();

	menuBgSprite.setTexture(menuBgTexture);
	menuBgSprite.setScale(0.7, 0.85);
}


/// <summary>
/// check current position of the mouse for intersection with
/// location of buttons using locations and offsets rather than rectangles
/// for intersection (create said so 'imaginary' columns and rows, then mouse x/y 
/// values are compared to see if they are intersecting columns' then rows' x/y values
/// </summary>
void Menu::update(sf::Window& window)
{
	selectionNumber = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y && mouseLocation.y < m_topOffset + m_buttonHeight)
			{
				selectionNumber = 1;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				selectionNumber = 2;
			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)
			{
				selectionNumber = 3;
			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 3 && mouseLocation.y < m_topOffset + m_verticalSpacing * 3 + m_buttonHeight)
			{
				window.close();
			}
		}
	}
}


void Menu::draw(sf::RenderWindow& window)
{
	window.draw(menuBgSprite);

	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}

	
}

int Menu::getSelectionNumber()
{
	return selectionNumber;
}

void Menu::playMusic()
{
	m_menuMusic.play();
}


void Menu::changeVolume()
{
	m_menuMusic.setVolume(5.f);
}
