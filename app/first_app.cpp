#include "first_app.hpp"

namespace lve {

	void FirstApp::run() {
		// "Game Loop"
		while (!lveWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
} // namespace lve