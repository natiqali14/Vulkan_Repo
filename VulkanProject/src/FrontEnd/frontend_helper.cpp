#include "frontend_helper.h"
#include "../utils/logger.h"
void glfw_error_callback(int error, const char* description)
{
	log_msg(stderr, "---- GLFW ERROR ---- \n ERROR CODE: %d\nERROR DESCRIPTION: \n",
		 error, description);
}
