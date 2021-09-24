
#include "Player.h"

void Player::init()
{
	if (!playerTextureSheet.loadFromFile("./resources/images/playerSpriteSheet.png"))
	{
		std::cout << "gray error" << std::endl;
	}

	if (!m_gunSoundBuffer.loadFromFile("./resources/audio/gunSound.wav"))
	{
		std::string s("Error loading gun sound");
		throw std::exception(s.c_str());
	}
	m_gunSound.setBuffer(m_gunSoundBuffer);


	spriteSheet.setTexture(playerTextureSheet);
	rotation = -90;
	rotationSpeed = 1;
	movingSpeed = 1;
	InitAnimationData();
	spriteSheet.setOrigin(spriteSheet.getGlobalBounds().width / 4, spriteSheet.getGlobalBounds().height / 6);
	spriteSheet.setPosition(800, 600);
	spriteSheet.setScale(1.5, 1.5);
	spriteSheet.rotate(rotation);
}

void Player::updateSpeed(int speed)
{
	movingSpeed = speed;
}

void Player::chooseTexture(int selectioNumber)
{
	if (selectioNumber == 1)
	{
		if (!playerTextureSheet.loadFromFile("./resources/images/playerSpriteSheet_blue.png"))
		{
			std::cout << "blue error" << std::endl;
		}
	}
	else if (selectioNumber == 2)
	{
		if (!playerTextureSheet.loadFromFile("./resources/images/playerSpriteSheet_brown.png"))
		{
			std::cout << "brown error" << std::endl;
		}
	}
	else if (selectioNumber == 3)
	{
		if (!playerTextureSheet.loadFromFile("./resources/images/playerSpriteSheet.png"))
		{
			std::cout << "gray error" << std::endl;
		}
	}
	spriteSheet.setTexture(playerTextureSheet);
}

void Player::InitAnimationData()
{
	animations[int(PlayerAnimationState::walk)] = { 2,1,10,true };
	animations[int(PlayerAnimationState::run)] = { 16,1,0.2,true };
	animations[int(PlayerAnimationState::jump)] = { 16,1,0.2,false };
	animations[int(PlayerAnimationState::idle)] = { 16,1,0.2,true };
	animationState = PlayerAnimationState::walk;
	animSheet.Init(spriteSheet.getGlobalBounds().width,
		spriteSheet.getGlobalBounds().height, 3, 1);


}

void Player::startAnimation(PlayerAnimationState _animationState)
{
	animationState = _animationState;
	animSheet.StartAnimation(animations[int(animationState)]);
}

void Player::Draw(sf::RenderWindow& win)
{
	animSheet.nextFrame();
	spriteSheet.setTextureRect(animSheet.GetFrame());
	win.draw(spriteSheet);
}

void Player::Update()
{
	detectMovementInput();
}

void Player::detectMovementInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isPlayerShooting = true;
	}
	else
	{
		isPlayerShooting = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (isPlayerShooting == false)
		{
			movementUp();
			rotation = -90;
		}
		spriteSheet.setRotation(rotation);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (isPlayerShooting == false)
		{
			movementDown();
			rotation = 90;
		}

		spriteSheet.setRotation(rotation);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (isPlayerShooting == false)
		{
			movementLeft();
			rotation = 180;
		}
		else if (isPlayerShooting)
		{
			rotateLeft();
		}
		spriteSheet.setRotation(rotation);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (isPlayerShooting == false)
		{
			movementRight();
			rotation = 0;
		}
		else if (isPlayerShooting)
		{
			rotateRight();
		}
		spriteSheet.setRotation(rotation);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		sneak();
	}
	else
	{
		movingSpeed = 1;
	}
}

void Player::movementUp()
{
	spriteSheet.move(0, -movingSpeed);
}

void Player::movementDown()
{
	spriteSheet.move(0, movingSpeed);
}


void Player::rotateLeft()
{
	rotation -= rotationSpeed;
}

void Player::rotateRight()
{
	rotation += rotationSpeed;
}

void Player::sneak()
{
	movingSpeed = 0.4;
}

void Player::movementLeft()
{
	spriteSheet.move(-movingSpeed, 0);
}

void Player::movementRight()
{
	spriteSheet.move(movingSpeed, 0);
}

void Player::playGunSound()
{
	m_gunSound.play();
}
