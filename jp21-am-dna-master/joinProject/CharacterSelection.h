#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class CharacterSelection
{
private:

    int selectionNumber = 0;
    double scaleAmount = 5;

    // speeds at whuch the selection sprites scale
    const double SCALE_SPEED = 1.0001;
    const double SCALE_SPEED_DECREASE = 0.9999;
    // when true sprites scale higher
    bool areSpritesScalingUp = true;

    sf::Sprite brownShirtSprite;
    sf::Texture brownShirtTexture;

    sf::Sprite blueShirtSprite;
    sf::Texture blueShirtTexture;

    sf::Sprite grayShirtSprite;
    sf::Texture grayShirtTexture;

public:


    void setupSprites(sf::Font& font);

    void draw(sf::RenderWindow& window);

    void update(sf::Window& window);

    static const int m_optionCount = 3;
    /// green button background
    sf::Texture m_buttonTexture;
    /// array of sprites used to display buttons
    sf::Sprite m_buttonSprites[m_optionCount];
    /// local refrence to font used by whole game
    sf::Font m_font;
    /// array of text objects for text on buttons
    sf::Text m_buttonTexts[m_optionCount];

    /// top left of area used for menu
    float m_topOffset;
    /// top left of area used for menu
    float m_leftOffset;
    /// gap in pixels between sides of buttons
    float m_horizontalSpacing;
    /// width in pixels of all buttons
    float m_buttonWidth;
    /// height of button in pixels must be less than vertical spacing
    float m_buttonHeight;
    /// <summary>
    /// returns selectionNumber
    /// </summary>
    /// <returns></returns>
    int getSelectionNumber();
};