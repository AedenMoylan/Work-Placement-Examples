#pragma once
#include "State.h"
#include <iostream>

using namespace std;

class CheckDagger : public State
{
public:
    CheckDagger() {};
    ~CheckDagger() {};

    void idle(Animation* a)
    {
        cout << "idle to dagger from checkDagger.h" << endl;
        a->setCurrent(new Idle());
        delete this;
    }
};