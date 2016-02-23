#pragma once
#include "graphics.h"
#include "spriteSheet.h"
class GameLevel
{ 
protected:
	static Graphics* gfx;

public:
	static void Init(Graphics* graphics)
	{
		gfx = graphics;
	}
	bool Loading();
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};