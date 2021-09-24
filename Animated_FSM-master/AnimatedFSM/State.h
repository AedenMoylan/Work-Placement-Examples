#pragma once
#include "Animation.h"
#include <iostream>

using namespace std;

class State
{
public:
	virtual void idle(Animation* a)
	{
		cout << "idle from state.h " << endl;
	}

	virtual void jumping(Animation* a)
	{
		cout << "jumping from state.h " << endl;
	}

	virtual void climbing(Animation* a)
	{
		cout << "climbing from state.h " << endl;
	}

	virtual void doubleJumping(Animation* a)
	{
		cout << "double jumping from state.h " << endl;
	}

	virtual void checkDagger(Animation* a)
	{
		cout << "check dagger from state.h " << endl;
	}

	virtual void movePlayer(Animation* a)
	{
		cout << "move player from state.h " << endl;
	}
};