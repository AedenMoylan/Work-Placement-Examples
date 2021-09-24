
#include "Zombie.h"

void Zombie::init()
{
	health = 20;
	position = { 20, 20 };
	InitAnimationData();

	spriteSheet.setPosition(position);
	spriteSheet.setScale(0.6, 0.6);
}

void Zombie::InitAnimationData()
{

	animations[int(ZombieAnimationState::walk)] = { 15,1,2,true };
	animations[int(ZombieAnimationState::run)] = { 16,1,0.2,true };
	animations[int(ZombieAnimationState::jump)] = { 16,1,0.2,false };
	animations[int(ZombieAnimationState::idle)] = { 16,1,0.2,true };
	animationState = ZombieAnimationState::walk;
	animSheet.Init(spriteSheet.getGlobalBounds().width,
		spriteSheet.getGlobalBounds().height, 4, 4);

}

void Zombie::startAnimation(ZombieAnimationState _animationState)
{
	animationState = _animationState;
	animSheet.StartAnimation(animations[int(animationState)]);
}

void Zombie::Draw(sf::RenderWindow& win)
{
	animSheet.nextFrame();
	spriteSheet.setTextureRect(animSheet.GetFrame());
	win.draw(spriteSheet);
}


int Zombie::getHealth()
{
	return health;
}

void Zombie::reduceHealth()
{
	health -= HEALTH_REDUCTION_AMOUNT;
}

sf::Vector2f Zombie::getPosition()
{
	return position;
}

void Zombie::move(sf::Vector2f _targetLocation)
{
	if (position.x < _targetLocation.x)
	{
		position.x++;
	}
	else if (position.x > _targetLocation.x)
	{
		position.x--;
	}
	else
	{
		position.x = _targetLocation.x;
	}

	if (position.y < _targetLocation.y)
	{
		position.y++;
	}
	else if (position.y > _targetLocation.y)
	{
		position.y--;
	}
	else
	{
		position.y = _targetLocation.y;
	}

	spriteSheet.setPosition(position.x, position.y);

}
