#include "gameController.h"

GameLevel* GameController::currentLevel;
bool GameController::Loading;

void GameController::Init()
{
	Loading = true;
	currentLevel = 0;
}

// Loads up starting level
void GameController::LoadInitialLevel(GameLevel* lev)
{
	Loading = true;
	currentLevel = lev;
	currentLevel->Load();
	Loading = false;
}

// Calls unload function of the level and then calls the load function of another level
void GameController::SwitchLevel(GameLevel* lev)
{
	Loading = true;
	currentLevel->Unload();
	lev->Load();
	delete currentLevel;
	currentLevel = lev;
	Loading = false;
}

// Calls the render function for the current level
void GameController::Render()
{
	if (Loading) return;
	currentLevel->Render();
}

// Calls the update function for the current level
void GameController::Update()
{
	if (Loading) return;
	currentLevel->Update();
}