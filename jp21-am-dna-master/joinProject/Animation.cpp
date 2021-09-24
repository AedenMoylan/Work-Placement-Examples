#include "Animation.h"

// initialises the number of columns, rows, and frame sizes of the sprite sheet
void AnimationSheet::Init(int _pixelWidth, int _pixelHeight, int _numRows, int _numCols)
{

    numCols = _numCols;
    numRows = _numRows;
    frameSize.x = _pixelWidth / numCols;
    frameSize.y = _pixelHeight / numRows;
    curFrameOffset = 0;
}

// returns the rectangle frame around an image in a spritesheet
sf::IntRect AnimationSheet::GetFrame()
{

    int row = curFrameOffset / numCols;
    int col = curFrameOffset % numCols;
    sf::IntRect frameRectangle;
    frameRectangle.left = col * frameSize.x;
    frameRectangle.top = row * frameSize.y;
    frameRectangle.width = frameSize.x;
    frameRectangle.height = frameSize.y;
    return frameRectangle;
}

// sets the current animation and sets the frame counter to 0 which ppays the animation from the start
void AnimationSheet::StartAnimation(Animation curAnimation)
{

    this->curAnimation = curAnimation;
    frameCounter = 0;
    curFrameOffset = curAnimation.startOffset;
}

// move to the next frame in the spritesheet based on how fast the  curAnimation.speed variable is
void AnimationSheet::nextFrame()
{
    if (frameCounter > curAnimation.speed)
    {
        frameCounter = 0;
        if (curFrameOffset >= curAnimation.startOffset + curAnimation.numframes - 1)
        {
            if (curAnimation.loop == true)
            {
                curFrameOffset = curAnimation.startOffset;
            }
            else {
                curFrameOffset = curAnimation.startOffset + curAnimation.numframes - 1;
            }
        }
        else {
            curFrameOffset++;
        }
    }
    else {
        frameCounter++;
    }
}