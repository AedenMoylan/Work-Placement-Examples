#pragma once
#include "State.h"
#include <iostream>

using namespace std;

class DoubleJumping : public State
{
public:
    DoubleJumping() {};
    ~DoubleJumping() {};

    void idle(Animation* a)
    {
        cout << "idle to double jumping from doublejumping.h" << endl;
        a->setCurrent(new Idle());
        delete this;
    }
};
