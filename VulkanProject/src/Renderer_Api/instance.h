#pragma once
#include "../defines.h"
bool support_extensions(std::vector<const char*> required_props);
bool support_layers(std::vector<const char*> required_props);
bool make_vulkan_instance(const char* application_name, struct vulkan_context& context);
VKAPI_ATTR VkBool32 VKAPI_CALL vk_debug_callback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
	void* user_data
);
