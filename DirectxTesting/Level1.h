#pragma once
#include "gameLevel.h"
#include "PlayerController.h"

class Level1: public GameLevel
{
public:
	bool Loading();
	// Set up sprite sheet here for rendering in the level
	SpriteSheet* sprites;
	Player movement;

	 void Load() override;
	 void Unload() override;
	 void Update() override;
	 void Render() override;
};