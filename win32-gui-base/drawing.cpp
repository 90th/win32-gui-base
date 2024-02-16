#include "drawing.h"

// Drawing constructor
Drawing::Drawing(HWND hWnd) : hWnd(hWnd) {}

// Drawing destructor
Drawing::~Drawing() {}

// Draw Lorem Ipsum text on the main window
void Drawing::DrawLoremIpsumText() {
	// Initialize the device context
	HDC hdc = InitializeDeviceContext();
	if (hdc == nullptr) {
		return;
	}

	// Set text color to black
	SetTextColor(hdc, RGB(0, 0, 0));

	// Set text background mode to transparent
	SetBkMode(hdc, TRANSPARENT);

	// Select a font
	HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
	HFONT hPrevFont = static_cast<HFONT>(SelectObject(hdc, hFont));

	// Define the rectangle to draw text
	RECT rect;
	rect.left = 20;
	rect.top = 20;
	rect.right = 780; // Adjust width as needed
	rect.bottom = 580; // Adjust height as needed

	// Text to draw (Lorem Ipsum)
	const wchar_t* loremIpsumText = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

	// Draw text
	DrawText(hdc, loremIpsumText, -1, &rect, DT_WORDBREAK | DT_LEFT);

	// Clean up resources
	SelectObject(hdc, hPrevFont);
	DeleteObject(hFont);
	ReleaseDeviceContext(hdc);
}

// Initialize the device context
HDC Drawing::InitializeDeviceContext() {
	HDC hdc = GetDC(hWnd);
	if (hdc == nullptr) {
		MessageBox(nullptr, L"Failed to get device context.", L"Error", MB_OK | MB_ICONERROR);
	}
	return hdc;
}

// Release the device context
void Drawing::ReleaseDeviceContext(HDC hdc) {
	ReleaseDC(hWnd, hdc);
}

// Note to developers:
// This code demonstrates how to draw text onto the main window using the Win32 API.
// The DrawLoremIpsumText method initializes the device context, selects a font, defines the drawing rectangle, and draws Lorem Ipsum text onto the window.
// Developers can customize and extend this code to draw various UI elements and text with different styles, sizes, and colors.