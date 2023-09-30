#pragma once
#include "frontend_helper.h"
#include "../defines.h"
class GLFW_Window
{
	u32 window_width;
	u32 window_height;
	const char* window_name;
	GLFWwindow* window;
	u8 setup_window();
public:
	GLFW_Window(u32 width,u32 height,const char* name);
	GLFWwindow* get_window();
	bool should_window_close();
	bool create_window_surface(struct vulkan_context& context);
	~GLFW_Window();
};

