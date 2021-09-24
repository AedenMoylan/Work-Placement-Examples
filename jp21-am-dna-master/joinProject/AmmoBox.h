#pragma once
#include<SFML/Graphics.hpp>

class Ammobox
{
private:
    // sprite and texture for ammo box
    sf::Sprite ammoBoxSprite;
    sf::Texture ammoBoxTexture;

    // used to detect when the ammo box is picked up by the player
    bool isAmmoCollected = false;

public:

    /// <summary>
    /// extracts texture and sets the position, scale, and texture
    /// </summary>
    void init();

    /// <summary>
    /// draws ammoBoxSprite
    /// </summary>
    /// <param name="window"></param>
    void draw(sf::RenderWindow& window);

    /// <summary>
    /// returns ammo box
    /// </summary>
    /// <returns></returns>
    bool getIsAmmoCollected();

    /// <summary>
    /// sets isAmmoCollected to the passed value
    /// </summary>
    /// <param name="hasPlayerCollect"></param>
    void setIsAmmoCollected(bool hasPlayerCollect);

    /// <summary>
    /// returns ammoBoxSprite
    /// </summary>
    /// <returns></returns>
    sf::Sprite getSprite();
};