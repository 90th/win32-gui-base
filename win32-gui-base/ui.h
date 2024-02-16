#pragma once
#include <Windows.h>
#include <memory>
#include "drawing.h"
class UI {
public:
	UI();
	~UI();

	// Function to initialize the main window
	bool InitMainWindow(HINSTANCE hInstance, int nCmdShow);

	// Function to get the handle of the main window
	HWND GetMainWindowHandle() const;

private:
	std::unique_ptr<HWND> hWnd;
	int windowWidth;
	int windowHeight;

	// Function to register the window class
	bool RegisterWindowClass(HINSTANCE hInstance);

	// Function to create the main window
	bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow);

	// Static window procedure callback function
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::unique_ptr<Drawing> drawing; // Declare drawing object as a member variable
};
