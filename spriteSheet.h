#pragma once
#include <wincodec.h> //WIC codec header for decoding image from file
#include "graphics.h" // Include windows and d2d1.h
// Link to windows.codec.lib

class SpriteSheet
{
	Graphics* gfx; //Reference to the graphics class
	ID2D1Bitmap* bmp; // Bitmap loaded file and converted to Direct2D
public:
	// constructor
	SpriteSheet(wchar_t* filename, Graphics* gfx);

	// Destructor
	~SpriteSheet();

	// Draw the bitmap to the render target
	void Draw();
};