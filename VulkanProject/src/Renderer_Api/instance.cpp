#include "instance.h"
#include <vulkan/vulkan.h>
#include "../utils/logger.h"
#include "renderer_types.h"
#include "vulkan_utils/vulkan_helper.h"
#include "../utils/assertions.h"

bool support_extensions(std::vector<const char*> required_props)
{
	uint32_t extension_count;
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);
	std::cout << "Total extension props: " << extension_count << std::endl;
	VkExtensionProperties* extension_props = (VkExtensionProperties*)malloc(extension_count * sizeof(VkExtensionProperties));
	vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, extension_props);
	bool b_flag = true;
	if (!extension_props) return false;
	for (auto prop : required_props) {
		bool b_found = false;
		for (int i = 0; i < extension_count; i++) {
			if (strcmp(prop, (&extension_props[i])->extensionName) == 0) {
				b_found = true;
				break;
			}
		}
		if (!b_found) {
			b_flag = false;
			std::cout << prop << " : Extension not found" << '\n';
		}
	}
	return b_flag;
}

bool support_layers(std::vector<const char*> required_props)
{
	uint32_t layer_count;
	vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
	std::cout << "Total layer props: " << layer_count << std::endl;
	VkLayerProperties* layer_props = (VkLayerProperties*)malloc(layer_count * sizeof(VkLayerProperties));
	vkEnumerateInstanceLayerProperties(&layer_count, layer_props);
	if (!layer_props) return false;
	bool b_flag = true;
	for (auto prop : required_props) {
		bool b_found = false;
		for (int i = 0; i < layer_count; i++) {
			if (strcmp(prop, (&layer_props[i])->layerName) == 0) {
				b_found = true;
				break;
			}
		}
		if (!b_found) {
			b_flag = false;
			std::cout << prop << " : Layer not found" << '\n';
		}
	}
	return b_flag;
}

VKAPI_ATTR VkBool32 VKAPI_CALL vk_debug_callback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
	void* user_data
)
{
	switch (messageSeverity)
	{
	default:
	case  VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
		log_msg_fatal(stderr, callback_data->pMessage);
		break;
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
		log_msg(stderr, callback_data->pMessage);
		break;
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
		log_msg(stderr, callback_data->pMessage);
		break;
	}
	return VK_FALSE;
}

bool make_vulkan_instance(const char* application_name, vulkan_context& context)
{
	uint32_t version;
	VkResult result = vkEnumerateInstanceVersion(&version);
	//	version = VK_MAKE_API_VERSION(0, 1, 3, 0); // Or you can do like that to make a specific version to use it with more devices.

	if (result != VK_SUCCESS) {

		context.instance = NULL;
		log_msg_fatal(stderr, "Instancing failed due to low host memory");
		return false;
	}

	VkApplicationInfo app_info;
	app_info.sType = VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pNext = nullptr;
	app_info.pApplicationName = application_name;
	app_info.apiVersion = version;
	app_info.pEngineName = "Vulkan Engine";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);

	uint32_t extensions_count;
	const char** extensions_name;

	/* Getting extensions required by GLFW */
	extensions_name = glfwGetRequiredInstanceExtensions(&extensions_count);
	std::vector<const char*> extensions(extensions_name, extensions_name + extensions_count);

	/* Adding debug util extension if in debug mode */
	if (DEBUG_MODE) extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	std::vector<const char*> layers{};
	/* Adding validation layer */
	layers.push_back("VK_LAYER_KHRONOS_validation");
	if (!support_extensions(extensions) || !support_layers(layers)) {
		context.instance = NULL;
		log_msg_fatal(stderr, "All Supports or Layers are not supported");
		return false;
	};
	/* vk instance creation */
	VkInstanceCreateInfo instance_create_info;
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pNext = nullptr;
	instance_create_info.flags = {};
	instance_create_info.pApplicationInfo = &app_info;
	instance_create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	instance_create_info.ppEnabledExtensionNames = extensions.data();
	instance_create_info.enabledLayerCount = static_cast<uint32_t>(layers.size()); // for now no layers
	instance_create_info.ppEnabledLayerNames = layers.data();
	VkResult r = vkCreateInstance(&instance_create_info, nullptr, &context.instance);
	VK_ASSERT(r, "Vulkan instance creation failed");
	// For making a debug validation layers
#if DEBUG_MODE
	VkDebugUtilsMessengerCreateInfoEXT debug_utils_create_info {VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT};
	debug_utils_create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
											  VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT |
											  VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
	debug_utils_create_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
										  VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT |
										  VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
	debug_utils_create_info.pfnUserCallback = vk_debug_callback;

	PFN_vkCreateDebugUtilsMessengerEXT func =
		(PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(context.instance, "vkCreateDebugUtilsMessengerEXT");
	VK_ASSERT(func(context.instance, &debug_utils_create_info, context.allocator, &context.vk_debugger))
#endif
	return true;

}
