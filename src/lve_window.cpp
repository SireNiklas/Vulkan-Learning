#include "lve_window.hpp"

namespace lve {

	// Constructor
	// A constructor in C++ is a special 'MEMBER FUNCTION' having the same name as that of its class which is used to initialize some valid values to the data members of an object.
	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	// Deconstructor
	// Usually used to deallocate memory and do other cleanup for a class object and its class members when the object is destroyed.
	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	// Initialization for creating the window.
	void LveWindow::initWindow() {
		// GLFW Init and Params
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
		// Window creation.
		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
} // namespace lve