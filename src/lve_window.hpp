#pragma once

#define GLFW_INCLUDE_VULKAN // Include Vulkan headers with GLFW
#include <GLFW/glfw3.h>

#include <string>

namespace lve {
	class LveWindow {
		// Defintions to be used in the CPP file.
		public:
			LveWindow(int w, int h, std::string name); // Constructor to initialize
			~LveWindow(); // Destructor to clean up

			// Cleanups are handled by our constructor and destructor.
			LveWindow(const LveWindow&) = delete;
			LveWindow& operator=(const LveWindow&) = delete;

			bool shouldClose() { return glfwWindowShouldClose(window); }
			VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

			void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		private:
			void initWindow();

			const int width;
			const int height;

			std::string windowName;

			GLFWwindow* window;
	};
} // namespace lve