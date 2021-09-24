#pragma once
#include "Animation.h"
#include "State.h"

using namespace std;

class Idle : public State
{
public:
    Idle() {};
    ~Idle() {};
    void jumping(Animation* a);
    void climbing(Animation* a);
    void doubleJumping(Animation* a);
    void checkDagger(Animation* a);
    void movePlayer(Animation* a);
};