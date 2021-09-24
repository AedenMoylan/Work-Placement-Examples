#pragma once
#include "State.h"
#include <iostream>

using namespace std;

class Jumping : public State
{
public:
    Jumping() {};
    ~Jumping() {};
    
    void idle(Animation* a)
    {
        cout << "idle to jumping from jumping.h" << endl;
        a->setCurrent(new Idle());
        delete this;
    }
};