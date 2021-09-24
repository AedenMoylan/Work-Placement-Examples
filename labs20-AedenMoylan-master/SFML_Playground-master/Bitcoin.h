#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenSize.h"
#include "Tank.h"
#include "LevelLoader.h"
#include "CollisionDetector.h"
#include "TankAI.h"
#include "GameState.h"
#include "HUD.h"

class Bitcoin
{
public:
	sf::Sprite m_bitcoinSprite;
	sf::Texture m_bitcoinTexture;

	void init();
	void draw(sf::RenderWindow& window);
	void update(sf::Vector2f t_tankPos);

	bool didPlayerCollectCoin = false;

};

