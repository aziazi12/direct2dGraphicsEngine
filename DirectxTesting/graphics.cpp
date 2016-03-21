#include "graphics.h"

Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
	brush = NULL;
}

Graphics::~Graphics()
{
	if (factory) { factory->Release(); }
	if (renderTarget) {renderTarget->Release();}
	if (brush) { brush->Release(); }
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &factory);
	if (res != S_OK) return false;

	RECT rect;
	GetClientRect(windowHandle, &rect);

	res = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);

	if (res != S_OK) return false;

	renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &brush);

	if (res != S_OK) return false;
	return true;
}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
	
}

void Graphics::DrawRect(float positionX, float positionY, float height, float width, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	D2D1_RECT_F rectangle = D2D1::RectF(
		positionX - (height + 5.0f),
		positionY - (width + 5.0f),
		positionX + (height + 5.0f),
		positionY + (width + 5.0f));
	renderTarget->DrawRectangle(&rectangle, brush);
}
bool CollisionCheck(float positionX, float positionY, float position2X, float position2Y, float height, float width, float height2, float width2)
{
	int x1Min = positionX;
	int x1Max = positionX + width;
	int y1Max = positionY + height;
	int y1Min = positionY;

	int x2Min = position2X;
	int x2Max = position2X + width2;
	int y2Max = position2Y + height2;
	int y2Min = position2Y;

	if (x1Max < x2Min || x1Min > x2Max) return false;
	if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;
}