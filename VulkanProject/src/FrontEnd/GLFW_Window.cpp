#include "GLFW_Window.h"
#include "../utils/logger.h"
#include "../Renderer_Api/renderer_types.h"
#include "../Renderer_Api/vulkan_utils/vulkan_helper.h"



GLFW_Window::GLFW_Window(u32 width, u32 height, const char* name):
	window(nullptr), window_width(width), window_height(height), window_name(name)
{
	setup_window();
}

GLFWwindow* GLFW_Window::get_window()
{
	return window;
}

bool GLFW_Window::should_window_close()
{
	return glfwWindowShouldClose(window);
}



u8 GLFW_Window::setup_window()
{
	if (glfwInit() == GLFW_FALSE) {
		log_msg_fatal(stderr, "glfw initialization failed");
		glfwTerminate();
		return -1;
	}
	/* no rendering from it, Will hook up Vulkan for it */
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	/* Give crash after resizing*/
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	/* params for below function -> window width, height, ptr to monitor, ptr to a shared window */
	window = glfwCreateWindow(window_width, window_height, window_name, nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		log_msg_fatal(stderr, "Window Creation failed");
		return false;
	}
	glfwSetErrorCallback(glfw_error_callback);
	return 0;
}

bool GLFW_Window::create_window_surface(vulkan_context& context)
{
	// for some reasons this is not working
	// glfwCreateWindowSurface(context.instance, window, context.allocator, &context.vk_surface);
	VkResult r = glfwCreateWindowSurface(context.instance, window, context.allocator, &context.vk_surface))
	VK_ASSERT_MSG(r,"Vulkan Surface creation failed");
	return true;
}
GLFW_Window::~GLFW_Window()
{
	if (window) glfwDestroyWindow(window);
	glfwTerminate();
}
