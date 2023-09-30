#include "renderer_types.h"

/* Abstraction layer that will provide the renderer functionality to application layer */
struct engine_data;
struct static_mesh_data;
bool renderer_initialize(const char* application_name, engine_data data);
void renderer_shutdown();
void renderer_on_resize(u16 width, u16 hight);
bool renderer_begin_frame(u64 delta);
bool renderer_end_frame(u64 delta);


bool renderer_draw_frame(render_packet* frame_packet);