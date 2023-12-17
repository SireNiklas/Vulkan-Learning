#pragma once

#include "lve_device.hpp"

#define GLM_FOR_RADIANS // Helps save time by not working in degrees.
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

// std
#include <vector>

namespace lve {
	class LveModel {
		public:

			struct Vertex {
				glm::vec2 position;

				static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
				static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
			};

			LveModel(LveDevice &device, const std::vector<Vertex>& vertices);
			~LveModel();

			// Cleanups are handled by our constructor and destructor.
			LveModel(const LveModel&) = delete;
			LveModel& operator=(const LveModel&) = delete;

			void bind(VkCommandBuffer commandBuffer);
			void draw(VkCommandBuffer commandBuffer);

		private:
			void createVertexBuffers(const std::vector<Vertex> &vertices);

			LveDevice& lveDevice;
			// These two somehow put us in charge of memory management.
			VkBuffer vertexBuffer;
			VkDeviceMemory vertexBufferMemory;
			uint32_t vertexCount;
	};
} // namespace lve