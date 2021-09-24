#include "Animation.h"
#include "Climbing.h"
#include "Idle.h"
#include "Jumping.h"
#include "State.h"

Animation::Animation()
{
	current = new Idle();

	if (!playerIdleTextureSheet.loadFromFile("./assets/Idle.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!playerRunRightTextureSheet.loadFromFile("./assets/RunRight.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!playerRunLeftTextureSheet.loadFromFile("./assets/RunLeft.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!playerJumpTextureSheet.loadFromFile("./assets/Jump.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!playerGlideTextureSheet.loadFromFile("./assets/Glide.png"))
	{
		std::cout << "error" << std::endl;
	}

	if (!playerCheckDaggerTextureSheet.loadFromFile("./assets/Attack.png"))
	{
		std::cout << "error" << std::endl;
	}

	playerSprite.setTexture(playerIdleTextureSheet);
	playerSprite.setPosition(100, 100);
	playerRect.height = 430;
	playerRect.width = 232;
	playerSprite.setTextureRect(playerRect);

}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::climbing()
{
	current->climbing(this);
}

void Animation::doubleJumping()
{
	current->doubleJumping(this);
}

void Animation::checkDagger()
{
	current->checkDagger(this);
}

void Animation::movePlayer()
{
	current->movePlayer(this);
}

void Animation::animateRunRight()
{
	playerSprite.setTexture(playerRunRightTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 5)
	{
		totalTimeElapsed = 0;
		animationFrameMoveRight++;
		if (animationFrameMoveRight > 10)
		{
			animationFrameMoveRight = 0;
		}
	}
	int col = animationFrameMoveRight % 3;
	int row = animationFrameMoveRight / 4;
	playerRect.height = 458;
	playerRect.width = 363;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);
}

void Animation::animateRunLeft()
{
	playerSprite.setTexture(playerRunLeftTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 5)
	{
		totalTimeElapsed = 0;
		animationFrameMoveLeft++;
		if (animationFrameMoveLeft > 10)
		{
			animationFrameMoveLeft = 0;
		}
	}
	int col = animationFrameMoveLeft % 3;
	int row = animationFrameMoveLeft / 4;
	playerRect.height = 458;
	playerRect.width = 363;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);
}

void Animation::animateIdle()
{
	playerSprite.setTexture(playerIdleTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 8)
	{
		totalTimeElapsed = 0;
		animationFrameIdle++;
		if (animationFrameIdle > 10)
		{
			animationFrameIdle = 0;
		}
	}
	int col = animationFrameIdle % 3;
	int row = animationFrameIdle / 4;
	playerRect.height = 439;
	playerRect.width = 232;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);

}

void Animation::animateJump()
{
	playerSprite.setTexture(playerJumpTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 5)
	{
		totalTimeElapsed = 0;
		animationFrameJumping++;
		if (animationFrameJumping > 10)
		{
			animationFrameJumping = 0;
		}
	}
	int col = animationFrameJumping % 3;
	int row = animationFrameJumping / 4;
	playerRect.height = 483;
	playerRect.width = 362;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);

}

void Animation::animateCheckDagger()
{
	playerSprite.setTexture(playerCheckDaggerTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 5)
	{
		totalTimeElapsed = 0;
		animationFrameCheckDagger++;
		if (animationFrameCheckDagger > 10)
		{
			animationFrameCheckDagger = 0;
		}
	}
	int col = animationFrameCheckDagger % 3;
	int row = animationFrameCheckDagger / 4;
	playerRect.height = 495;
	playerRect.width = 536;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);

}

void Animation::animatedGlide()
{
	playerSprite.setTexture(playerGlideTextureSheet);
	totalTimeElapsed++;
	if (totalTimeElapsed > 5)
	{
		totalTimeElapsed = 0;
		animationFrameGlide++;
		if (animationFrameGlide > 10)
		{
			animationFrameGlide = 0;
		}
	}
	int col = animationFrameGlide % 3;
	int row = animationFrameGlide / 4;
	playerRect.height = 454;
	playerRect.width = 443;
	playerRect.left = col * playerRect.width;
	playerRect.top = row * playerRect.height;
	playerSprite.setTextureRect(playerRect);

}