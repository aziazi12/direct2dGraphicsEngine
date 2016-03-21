#pragma once
#include <Windows.h>
#include <d2d1.h>

class Graphics
{
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
public:
	Graphics();
	~Graphics();

	ID2D1RenderTarget* GetRenderTarget()
	{
		return renderTarget;
	}

	bool Init(HWND windowHandle);
	void BeginDraw() { renderTarget->BeginDraw(); }
	void EndDraw() { renderTarget->EndDraw(); }
	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);
	void DrawRect(float positionX, float positionY, float height, float width, float r, float g, float b, float a);
	bool CollisionCheck(float positionX, float positionY, float position2X, float position2Y, float height, float width, float height2, float width2);

};
