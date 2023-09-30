 #include "VulkanRenderer.h"
#include "../Game/VulkanEngine.h"
#include "instance.h"
static vulkan_context context;
bool VulkanRenderer::initialize(const char* application_name, engine_data data)
{
	if (!make_vulkan_instance(application_name, context)) {
		// make_vulkan_instance will create vulkan instance and add
		// required extensions and validation (debuging) layer to it
		return false;
	};


	return true;
}

void VulkanRenderer::shutdown()
{
#if DEBUG_MODE
	PFN_vkDestroyDebugUtilsMessengerEXT func =
		(PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(context.instance, "PFN_vkDestroyDebugUtilsMessengerEXT");
	func(context.instance, context.vk_debugger, context.allocator);
#endif
	destroy_renderer_instance();
}

void VulkanRenderer::resize(u16 width, u16 height)
{
}

bool VulkanRenderer::begin_frame(u64 delta_time)
{
	return true;
}

bool VulkanRenderer::end_frame(u64 delta_time)
{
	return false;
}

void VulkanRenderer::destroy_renderer_instance()
{
	vkDestroyInstance(context.instance, context.allocator);
}
