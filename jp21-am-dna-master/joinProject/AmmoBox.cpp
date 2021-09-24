#include "AmmoBox.h"
#include <iostream>

void Ammobox::init()
{
    if (!ammoBoxTexture.loadFromFile("./resources/images/ammoBox.png"))
    {
        std::cout << "error" << std::endl;
    }
    ammoBoxSprite.setTexture(ammoBoxTexture);
    ammoBoxSprite.setScale(0.2, 0.2);
    ammoBoxSprite.setPosition(500, 500);
}

void Ammobox::draw(sf::RenderWindow& window)
{
    window.draw(ammoBoxSprite);
}

bool Ammobox::getIsAmmoCollected()
{
    return isAmmoCollected;
}

void Ammobox::setIsAmmoCollected(bool hasPlayerCollect)
{
    isAmmoCollected = hasPlayerCollect;
}

sf::Sprite Ammobox::getSprite()
{
    return ammoBoxSprite;
}