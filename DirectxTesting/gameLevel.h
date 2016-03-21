#pragma once
#include "graphics.h"
#include "spriteSheet.h"
class GameLevel
{ 
protected:
	static Graphics* gfx;
	static Graphics* move;
	static Graphics* move2;

public:
	static void Init(Graphics* graphics)
	{
		gfx = graphics;
		move = graphics;
	}
	bool Loading();
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};