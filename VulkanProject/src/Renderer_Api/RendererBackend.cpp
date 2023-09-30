#include "RendererBackend.h"

u64 RendererBackend::get_frame_number()
{
	return frame_number;
}

void RendererBackend::set_frame_number(u64 number)
{
	frame_number = number;
}
