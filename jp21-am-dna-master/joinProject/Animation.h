#pragma once
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation {
public:

    int numframes; // the number of frames for the animation
    int startOffset; // from which frame will it start based on the spritesheet
    double speed; // how fast should the animation run 
    bool loop; // wether the animation needed to be loop 
};

class AnimationSheet
{
private:

    int frameCounter;
    sf::Vector2i frameSize{ };
    int numRows = 0;
    int numCols = 0;
    Animation curAnimation;
    int curFrameOffset = 0;

public:

    void Init(int _pixelWidth, int _pixelHeight, int _numRows, int _numCols);

    sf::IntRect GetFrame();

    void StartAnimation(Animation curAnimation);

    void nextFrame();
};