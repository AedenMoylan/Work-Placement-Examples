#include "Bitcoin.h"

void Bitcoin::init() 
{
	if (!m_bitcoinTexture.loadFromFile("./resources/images/bitcoin.png"))
	{
		std::string s("Error loading textureeeeeee");
		throw std::exception(s.c_str());
	}

	m_bitcoinSprite.setTexture(m_bitcoinTexture);

	m_bitcoinSprite.setPosition(300, 300);

	m_bitcoinSprite.setScale(0.2, 0.2);
}

void Bitcoin::draw(sf::RenderWindow& window)
{
	window.draw(m_bitcoinSprite);
	
}

void Bitcoin::update(sf::Vector2f t_tankPos)
{
	int  x_Pos = t_tankPos.x;
	int  y_Pos = t_tankPos.y;

	m_bitcoinSprite.setPosition(x_Pos, y_Pos);
}