#pragma once
#include "renderer_types.h"

class RendererBackend {
	/* A simple interface to have n number of renderers lik vulkan, DirectX etc*/
	u64 frame_number;
public:
	virtual bool initialize(const char* application_name, struct engine_data data) = 0;
	virtual void shutdown() = 0;
	virtual void resize(u16 width, u16 height) = 0;
	virtual bool begin_frame(u64 delta_time) = 0;
	virtual bool end_frame(u64 delta_time) = 0;
	virtual void destroy_renderer_instance() = 0;
	u64 get_frame_number();
	void set_frame_number(u64 number);

};