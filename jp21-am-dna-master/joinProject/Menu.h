#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"

class Menu
{
	// instance of GameState
	GameState myGameState;

	/// <summary>
	/// used to change the gamestates when a button is pressed
	/// </summary>
	int selectionNumber = 0;

	/// Number of buttons on our menu
	static const int m_optionCount = 4;
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
	/// gap in pixels between tops of buttons
	float m_verticalSpacing;
	/// width in pixels of all buttons
	float m_buttonWidth;
	/// height of button in pixels must be less than vertical spacing
	float m_buttonHeight;

	// background sprite and texture for the menu
	sf::Sprite menuBgSprite;
	sf::Texture menuBgTexture;

	// plays the background music
	sf::Sound m_menuMusic;
	// buffer for the background music
	sf::SoundBuffer m_menuMusicBuffer;

public:
	/// <summary>
	/// initialises buttons and button layouts. loads textures of the buttons and sets them.
	///  loads the background music buffer and sets the buffer to m_menuMusic
	/// plays menu music and sets scale of the background sprite
	/// </summary>
	/// <param name=""></param>
	void initialise(sf::Font&);

	/// <summary>
	/// draws button sprites, button text, and background sprite
	/// </summary>
	/// <param name=""></param>
	void draw(sf::RenderWindow&);

	/// <summary>
	/// detetcs where a mouse clicks and assigns selection number a value based on where on the screen it clicked.
	/// </summary>
	/// <param name=""></param>
	void update(sf::Window&);

	/// <summary>
	/// plays the background music
	/// </summary>
	void playMusic();

	/// <summary>
	/// makes the music a bit quieter
	/// </summary>
	void changeVolume();

	/// <summary>
	/// returns selection number
	/// </summary>
	/// <returns></returns>
	int getSelectionNumber();

};
