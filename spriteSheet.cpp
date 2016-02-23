#include "spriteSheet.h"

SpriteSheet::SpriteSheet(wchar_t* filename, Graphics* gfx)
{
	//Init
	this->gfx = gfx; // Save the gfx parameter for later
	bmp = NULL; // NULL our ID2D1Bitmap to start with
	HRESULT hr; // HRESULT for checking errors

	// Create a WIC factory
	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory, // CLS ID of the object we're making
		NULL, // Not part of an aggregate
		CLSCTX_INPROC_SERVER, // DLL runs in the same process
		IID_IWICImagingFactory, // Ref to interface that communicates with the object
		(LPVOID*)&wicFactory); // The pointer that'll contain our factory

	// Create a decoder
	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		filename, // The file name
		NULL, // No preferred vendor
		GENERIC_READ, // We're reading the file, not writing
		WICDecodeMetadataCacheOnLoad, // Cache on load*
		&wicDecoder); // The decoder we're making

	// Read a frame from the image:
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	// Create a converter
	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	// Setup the converter
	hr = wicConverter->Initialize(
		wicFrame, // Frame
		GUID_WICPixelFormat32bppPBGRA, // Pixel format
		WICBitmapDitherTypeNone, // Irrelevant
		NULL, // No palette needed, irrelevant
		0.0, // Alpha transparency % irrelevant
		WICBitmapPaletteTypeCustom // Irrelevant
		);
	
	// Use the converter to create a D2D1Bitmap
	ID2D1Bitmap* bmp; // This will be a member variable!
	gfx->GetRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter, // Converter
		NULL, //D2D1_BITMAP_PROPERTIES
		&bmp // Destination D2D1 bitmap
		);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();
}

SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
}

// Draw the entire image at (0,0)
void SpriteSheet::Draw()
{
	gfx->GetRenderTarget()->DrawBitmap(
		bmp, // Bitmap
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height), // Destination rectangle
		1.0f, // Opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height) // Source rectangle
		);
}
