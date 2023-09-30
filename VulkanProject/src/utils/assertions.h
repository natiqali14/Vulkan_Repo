#include "logger.h"

#include <intrin.h>
#define ASSERT(expr) {                                                      \
	if(expr) {}                                                             \
	else {                                                                  \
		log_msg_fatal(stderr, "%s %s %s \n", #expr, __FILE__, __LINE__);    \
	    __debugbreak();                                                     \
	}                                                                       \
                                                                            \
}               

#define ASSERT_MSG(expr,msg) {                                                                 \
	if(expr) {}                                                                                \
	else {                                                                                     \
		log_msg_fatal(stderr, "%s %s %s \nMessage: %s \n", #expr, __FILE__, __LINE__,msg);     \
	    __debugbreak();                                                                        \
	}                                                                                          \
                                                                                               \
}  