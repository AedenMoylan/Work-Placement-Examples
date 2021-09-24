#include "Fuel.h"


void Fuel::init()
{
	if (!m_fuelTexture.loadFromFile("./resources/images/jerry.png"))
	{
		std::string s("Error loading textureeeeeee");
		throw std::exception(s.c_str());
	}

	if (!m_font.loadFromFile("./resources/fonts/18ARMY.otf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}

	m_fuelSprite.setTexture(m_fuelTexture);

	m_fuelSprite.setPosition(660, 400);

	m_fuelSprite.setScale(0.3, 0.3);



	m_fuelText.setFont(m_font);  // set the font for the text
	m_fuelText.setCharacterSize(40); // set the text size
	m_fuelText.setFillColor(sf::Color::White); // set the text colour
	m_fuelText.setPosition(500, 300);  // its position on the screen

	
	m_fuelShape.setOutlineColor(sf::Color::Red);
	m_fuelShape.setOutlineThickness(5);
	m_fuelShape.setPosition(550, 760);
}


void Fuel::draw(sf::RenderWindow& window)
{
	window.draw(m_fuelSprite);
	window.draw(m_fuelShape);
}

sf::Sprite Fuel::getFuel()
{
	return m_fuelSprite;
}

void Fuel::decreaseFuel(double t_tankSpeed)
{
	fuelAmount -= t_tankSpeed * 0.0001;
}


void Fuel::setRectangleSize()
{
	m_fuelShape.setSize(sf::Vector2f((fuelAmount / 5), 15));
}

