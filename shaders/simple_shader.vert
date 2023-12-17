#version 460

#extension GL_KHR_vulkan_glsl : enable

// in keyword signifies that it comes from a buffer.
layout(location=0) in vec2 position;

// Not typically hard coded, only done for "Hello Triangle"
//vec2 positions[3] = vec2[] (
//	vec2(0.0, -0.5),
//	vec2(0.5, 0.5),
//	vec2(-0.5, 0.5)
//);

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
}