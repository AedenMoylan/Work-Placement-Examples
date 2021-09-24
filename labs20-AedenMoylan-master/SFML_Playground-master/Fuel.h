#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenSize.h"
#include "Tank.h"
#include "LevelLoader.h"
#include "CollisionDetector.h"
#include "TankAI.h"
#include "GameState.h"
#include "HUD.h"




class Fuel
{




public:

	void draw(sf::RenderWindow& window);

	void init();

	/// <summary>
	/// decrease fuel based on tank speed
	/// </summary>
	/// <param name="t_tankSpeed"></param>
	void decreaseFuel(double t_tankSpeed);

	void setRectangleSize();

	sf::Sprite getFuel();

	sf::Sprite m_fuelSprite;

	sf::RectangleShape m_fuelShape ;

	sf::Texture m_fuelTexture;

	sf::Font m_font;

	sf::Text m_fuelText;

	int fuelAmount = 2000;

	const int fuelStartAmount = 2000;

private:


};

