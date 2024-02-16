#include <Windows.h>

#include "ui.h"

UI::UI() : windowWidth(800), windowHeight(600) {}

UI::~UI() {}

bool UI::InitMainWindow(HINSTANCE hInstance, int nCmdShow) {
	if (!RegisterWindowClass(hInstance))
		return false;

	if (!CreateMainWindow(hInstance, nCmdShow))
		return false;

	return true;
}

bool UI::RegisterWindowClass(HINSTANCE hInstance) {
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WindowProc, 0, 0, hInstance, nullptr,
						nullptr, (HBRUSH)(COLOR_WINDOW + 1), nullptr, L"MainWindowClass", nullptr };

	if (!RegisterClassEx(&wcex)) {
		MessageBox(nullptr, L"Failed to register window class.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	return true;
}

bool UI::CreateMainWindow(HINSTANCE hInstance, int nCmdShow) {
	// Create the window with WS_OVERLAPPEDWINDOW style
	hWnd = std::make_unique<HWND>(CreateWindow(L"MainWindowClass", L"win32-gui-base", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr));

	if (!(*hWnd)) {
		MessageBox(nullptr, L"Failed to create main window.", L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	ShowWindow(*hWnd, nCmdShow);
	UpdateWindow(*hWnd);

	return true;
}

HWND UI::GetMainWindowHandle() const {
	return *hWnd;
}

LRESULT CALLBACK UI::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_SIZE:
		// Window size changed, invalidate the window to trigger a redraw
		InvalidateRect(hWnd, nullptr, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}