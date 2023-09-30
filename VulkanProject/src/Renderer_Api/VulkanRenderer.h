#pragma once
#include "RendererBackend.h"
#include <vulkan/vulkan.h>


class VulkanRenderer : public RendererBackend
{
	/* Vulkan core renderer class implementing the interface */
public:
	VulkanRenderer() = default;
	virtual bool initialize(const char* application_name, struct engine_data data) override;
	virtual void shutdown() override;
	virtual void resize(u16 width, u16 height) override;
	virtual bool begin_frame(u64 delta_time) override;
	virtual bool end_frame(u64 delta_time) override;
	virtual void destroy_renderer_instance() override;
	~VulkanRenderer() = default;
};

