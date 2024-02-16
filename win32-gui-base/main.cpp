#include "ui.h"
#include "drawing.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// Create an instance of the UI class
	UI ui;

	// Initialize the main window
	if (!ui.InitMainWindow(hInstance, nCmdShow)) {
		return 1; // Return error code if initialization fails
	}

	// Create an instance of the Drawing class
	Drawing drawing(ui.GetMainWindowHandle()); // Pass the handle of the main window to the Drawing constructor

	// Draw Lorem Ipsum text on the main window
	drawing.DrawLoremIpsumText(); // Very bare example

	// Message loop
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}

// Note to developers:
// To create elements and place them onto the form in this Win32 GUI template:
// 1. Identify the UI elements you want to add to your application, such as buttons, labels, text boxes, etc.
// 2. Define classes for each type of UI element, encapsulating their properties and functionality (e.g., Button, Label).
// 3. Implement drawing methods within each UI element class to visually represent the element on the form.
// 4. Use the constructor of the UI element class to create instances of the elements, specifying their position, size, and other attributes.
// 5. Add logic to handle user interactions and events for each UI element, such as button clicks or text input.
// 6. Utilize the Drawing class to draw the elements onto the main window by calling appropriate drawing methods within the DrawLoremIpsumText method or other drawing functions.
// 7. Organize the placement of elements on the form by specifying their coordinates or using layout management techniques (e.g., grids, stacks).
// 8. Test the UI elements thoroughly to ensure they behave as expected and respond correctly to user input.
// 9. Iterate on the design and functionality of the UI elements based on user feedback and application requirements.
// 10. Refer to the provided code, documentation, and comments for further guidance and assistance in creating and placing elements onto the form.