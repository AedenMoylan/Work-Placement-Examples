#pragma once
#include "State.h"
#include <iostream>

using namespace std;

class MovePlayer : public State
{
public:
    MovePlayer() {};
    ~MovePlayer() {};

    void idle(Animation* a)
    {
        cout << "idle to movePlayer from movePlayer.h" << endl;
        a->setCurrent(new Idle());
        delete this;
    }
};