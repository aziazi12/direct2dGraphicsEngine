#pragma once
#include "gameLevel.h"

#define W 0x57
#define S 0x53
#define D 0x44
#define A 0x41
#define UP VK_UP
#define DOWN VK_DOWN
#define LEFT VK_LEFT
#define RIGHT VK_RIGHT

// Contains basic player information and movement settings

class Player
{
public:
	float CircleY = 300.0f;
	float CircleX = 375.0f;
	float Circle2X = 200.0f;
	float Circle2Y = 275.0f;
	float radius = 50.0f;
	float CircleSpeed = 5.0f;
	
	float getCircleX();
	float getCircleY();
	float getCircle2X();
	float getCircle2Y();
	float getCircleSpeed();
	float getRadius();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};




