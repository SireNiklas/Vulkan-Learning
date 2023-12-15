#pragma once

#include "../src/lve_window.hpp"
#include "../src/lve_pipeline.hpp"

namespace lve{
	class FirstApp {
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			void run();

		private:
			// When window is created, is automatically created via its constructor, and same for the destroy.
			LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan"};
			LvePipeline lvePipeline{ "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv" };
	};
}