#include "Idle.h"



void Idle::jumping(Animation* a)
{
	cout << "Jumping" << endl;
	a->setCurrent(new Idle);
	delete this;
}

void Idle::climbing(Animation* a)
{
	cout << "climbing" << endl;
	a->setCurrent(new Idle);
	delete this;
}

void Idle::doubleJumping(Animation* a)
{
	cout << "double jumping" << endl;
	a->setCurrent(new Idle);
	delete this;
}

void Idle::checkDagger(Animation* a)
{
	cout << "checking dagger" << endl;
	a->setCurrent(new Idle);
	delete this;
}

void Idle::movePlayer(Animation* a)
{
	cout << "moving player" << endl;
	a->setCurrent(new Idle);
	delete this;
}