#pragma once
#include "State.h"
#include "Idle.h"
#include <iostream>

using namespace std;

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a)
	{
		cout << "Climbing to idling" << endl;
		a->setCurrent(new Idle());
		delete this;
	}
};