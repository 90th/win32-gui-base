#pragma once
#include <Windows.h>

class Drawing {
public:
	Drawing(HWND hWnd);
	~Drawing();

	// Function to draw Lorem Ipsum text on the main window
	void DrawLoremIpsumText();

private:
	HWND hWnd; // Handle to the main window

	// Function to initialize the device context for drawing
	HDC InitializeDeviceContext();

	// Function to release the device context
	void ReleaseDeviceContext(HDC hdc);

	RECT windowRect;
};
