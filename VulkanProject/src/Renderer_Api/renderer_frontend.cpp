#include "renderer_frontend.h"
#include "../Game/VulkanEngine.h"
#include "VulkanRenderer.h"
#include "../utils/logger.h"

static RendererBackend* backend_renderer = nullptr;

bool renderer_initialize(const char* application_name, engine_data data)
{
	backend_renderer = new VulkanRenderer();
	if (!backend_renderer->initialize(application_name, data)) {
		log_msg_fatal(stderr, "Renderer initialization failed");
		return false;
	}
	backend_renderer->set_frame_number(0);
	return true;
}

void renderer_shutdown()
{
	backend_renderer->shutdown();
	delete backend_renderer;
}

void renderer_on_resize(u16 width, u16 hight)
{
}

bool renderer_begin_frame(u64 delta)
{
	return backend_renderer->begin_frame(delta);
}

bool renderer_end_frame(u64 delta)
{
	bool result = backend_renderer->end_frame(delta);
	backend_renderer->set_frame_number(backend_renderer->get_frame_number() + 1);
	return result;
}

bool renderer_draw_frame(render_packet* frame_packet)
{
	if (renderer_begin_frame(frame_packet->delta_time)) {
		bool result = renderer_end_frame(frame_packet->delta_time);
		if (!result) {
			log_msg_fatal(stderr,"End Frame failed Shutting down!!!");
		}
	}
	return true;
}
