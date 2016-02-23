#pragma once
#include "gameLevel.h"
#include "graphics.h"

class GameController
{
	GameController() {}
	static GameLevel* currentLevel;
public:
	static void Init();
	static bool Loading;
	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);
	static void Render();
	static void Update();
};