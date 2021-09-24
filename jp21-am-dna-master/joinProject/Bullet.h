#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MathUtility.h"
#include <functional>
class Bullet
{
private:
    //how fast the bullet will go 
    int speed = 5;

    bool isBulletActive = false;
    int counter = 0;

public:
    int numberOfBullet = 3;
    /// <summary>
    /// initialiser for the bullet
    /// </summary>
    void init();

    /// <summary>
    /// draw the bullet using sf::renderWindow
    /// </summary>
    /// <param name="window"></param>
    void draw(sf::RenderWindow& window);

    /// <summary>
    /// set the bullet position to player current position
    /// </summary>
    /// <param name="t_playerSprite"></param>
    void setBulletPosition(sf::Sprite t_playerSprite);

    /// <summary>
    /// update the bullet every 60 frame 
    /// </summary>
    void update();

    /// <summary>
    /// set the rotation of the bullet to the direction the player is facing so the bullet will face forward
    /// </summary>
    /// <param name="t_playerSprite"></param>
    void setRotation(sf::Sprite t_playerSprite);

    /// <summary>
    /// move the bullet in the direction that has been shot
    /// </summary>
    void moveBullet();

    //Bullet sprite
    sf::Sprite bulletSprite;
    sf::Texture bulletTexture;


    /// <summary>
    /// Despawn the bullet if the bullet is out of screen , collide with zombie or walls
    /// </summary>
    void despawnBullet();

    //The bullet positon
    sf::Vector2f bulletPosition;

    //Get counter
    int getCounter();

    /// <summary>
    /// sets isBulletActive to passed value
    /// </summary>
    /// <param name="_i"></param>
    void setIsBulletActive(bool _i);

    /// <summary>
    /// sets counter to passed value
    /// </summary>
    /// <param name="_i"></param>
    void setCounter(int _i);
    
};