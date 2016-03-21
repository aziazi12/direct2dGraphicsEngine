#include "PlayerController.h"

float Player::getCircleX()
{
	return CircleX;
}
float Player::getCircleY()
{
	return CircleY;
}
float Player::getCircle2X()
{
	return Circle2X;
}
float Player::getCircle2Y()
{
	return Circle2Y;
}
float Player::getCircleSpeed()
{
	return CircleSpeed;
}
float Player::getRadius()
{
	return radius;
}
void Player::moveUp()
{
	if (GetKeyState(W) & 0x8000)  { CircleY -= CircleSpeed; }
	if (GetKeyState(UP) & 0x8000) { Circle2Y -= CircleSpeed; }
}
void Player::moveDown()
{
	if (GetKeyState(S) & 0x8000) { CircleY += CircleSpeed; }
	if (GetKeyState(DOWN) & 0x8000) { Circle2Y += CircleSpeed; }
}
void Player::moveLeft()
{
	if (GetKeyState(A) & 0x8000) { CircleX -= CircleSpeed; }
	if (GetKeyState(LEFT) & 0x8000) { Circle2X -= CircleSpeed; }
}
void Player::moveRight()
{
	if (GetKeyState(D) & 0x8000) { CircleX += CircleSpeed; }
	if (GetKeyState(RIGHT) & 0x8000) { Circle2X += CircleSpeed; }
}