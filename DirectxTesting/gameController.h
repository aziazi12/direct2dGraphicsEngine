#pragma once
#include "gameLevel.h"
#include "graphics.h"

class GameController
{
	GameController() {}
	static GameLevel* currentLevel;
	//int GET_X_LPARAM(LPARAM lParam);
	//int GET_Y_LPARAM(LPARAM lParam);
	

public:
	static void Init();
	static bool Loading;
	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);
	static void Render();
	static void Update();
};