#pragma once
#include "../defines.h"

//typedef enum renderer_backend_type {
//	RENDERER_VULKAN,
//};

struct render_packet {
	u64 delta_time;
};

struct vulkan_device {
	VkPhysicalDevice physical_device;
	VkDevice logical_device;
};
struct vulkan_context {
	VkInstance instance;
	VkAllocationCallbacks* allocator = 0;
	VkSurfaceKHR vk_surface;
	vulkan_device vk_device;
#if DEBUG_MODE
	VkDebugUtilsMessengerEXT vk_debugger;
#endif
};