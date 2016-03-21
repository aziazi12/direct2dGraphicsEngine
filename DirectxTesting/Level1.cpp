#include "Level1.h"
#include "gameController.h"
#include "graphics.h"
#include "PlayerController.h"

void Level1::Load()
{
	// Assigns sprite variable a image and passes in the graphics variable name
	sprites = new SpriteSheet(L"background.jpg", gfx);
	
}

void Level1::Unload()
{
	// Delete sprites for when they either die, or when you need to switch levels
	delete sprites;
}

void Level1::Update()
{
	movement.moveUp();
	movement.moveDown();
	movement.moveLeft();
	movement.moveRight();
	
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	gfx->DrawCircle(movement.getCircleX(), movement.getCircleY(), movement.getRadius(), 1.0f, 1.0f, 1.0f, 1.0f);
	gfx->DrawRect(movement.getCircleX(), movement.getCircleY(), movement.getRadius(), movement.getRadius(), 1, 1, 1, 1);

	move->DrawCircle(movement.getCircle2X(), movement.getCircle2Y(), movement.getRadius(), 1.0f, 1.0f, 1.0f, 1.0f);
	move->DrawRect(movement.getCircle2X(), movement.getCircle2Y(), movement.getRadius(), movement.getRadius(), 1, 1, 1, 1);

	// Use the spritesheet variable and call the draw function in spritesheet.cpp to actually draw the image
	/*sprites->Draw();*/
}
