#pragma once
#include "gameLevel.h"

class Level1: public GameLevel
{
	float y;
	float ySpeed;
	SpriteSheet* sprites;
public:
	bool Loading();

	 void Load() override;
	 void Unload() override;
	 void Update() override;
	 void Render() override;
};