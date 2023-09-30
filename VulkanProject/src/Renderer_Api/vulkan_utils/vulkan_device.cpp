#include "vulkan_device.h"
#include "../renderer_types.h"
#include "vulkan_helper.h"

struct vulkan_physical_device_requirements {
	bool graphics;
	bool present;
	bool compute;
	std::vector<std::string> device_extension_names;
	bool sampler_anistropy;
	bool discretre;
};

bool select_physical_device(vulkan_context& context);

bool vulkan_device_create(vulkan_context& context)
{
	return false;
}

void vulkan_device_destroy(vulkan_context& context)
{
}

bool select_physical_device(vulkan_context& context) {
	u32 physical_count;
	VK_ASSERT_MSG(vkEnumeratePhysicalDevices(context.instance, &physical_count, nullptr),"Enumerate Physical Devices failed");
	if (physical_count == 0) {
		log_msg_fatal(stderr,"No Physical device found");
		return false;
	}
	//  VkPhysicalDevice physical_device[physical_count]; Compiler specific ;
	VkPhysicalDevice* physical_devices = (VkPhysicalDevice*)malloc(sizeof(VkPhysicalDevice) * physical_count);
	VK_ASSERT_MSG(vkEnumeratePhysicalDevices(context.instance, &physical_count, physical_devices), "Enumerate Physical Devices failed");

	for (int i = 0; i < physical_count; i++) {
		VkPhysicalDeviceProperties props;
		vkGetPhysicalDeviceProperties(physical_devices[i], &props);
		VkPhysicalDeviceMemoryProperties mem_props;
		vkGetPhysicalDeviceMemoryProperties(physical_devices[i], &mem_props);
		VkPhysicalDeviceFeatures features;
		vkGetPhysicalDeviceFeatures(physical_devices[i], &features);

		vulkan_physical_device_requirements requirements{};
		requirements.compute = true;
		requirements.device_extension_names = std::vector<std::string>{};
		requirements.discretre = true;
		requirements.graphics = true;
		requirements.present = true;
		requirements.sampler_anistropy = true;S
		requirements.device_extension_names.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

	}

}