#include "Level1.h"
#include "gameController.h"
#include "graphics.h"

void Level1::Load()
{
	y = ySpeed = 0.0f;
	
	sprites = new SpriteSheet(L"background.jpg", gfx);
}

void Level1::Unload()
{
	delete sprites;
}

void Level1::Update()
{
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 495)
	{
		y == 495;
		ySpeed = -30.0f;
	}
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	gfx->DrawCircle(
		375.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	sprites->Draw();
}
