#pragma once

#include "../src/lve_window.hpp"
#include "../src/lve_pipeline.hpp"
#include "../src/lve_device.hpp"
#include "../src/lve_swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace lve{
	class FirstApp {
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			FirstApp();
			~FirstApp();

			// Cleanups are handled by our constructor and destructor.
			FirstApp(const FirstApp&) = delete;
			FirstApp& operator=(const FirstApp&) = delete;

			void run();

		private:
			void createPipelinelayout();
			void createPipeline();
			void createCommandBuffers();
			void drawFrame();

			// When window is created, is automatically created via its constructor, and same for the destroy.
			LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan"};
			LveDevice lveDevice{lveWindow};
			LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() };
			std::unique_ptr<LvePipeline> lvePipeline;
			VkPipelineLayout pipelineLayout;
			std::vector<VkCommandBuffer> commandBuffers;
	};
}