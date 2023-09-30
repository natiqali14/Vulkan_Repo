#pragma once
#include "../../defines.h"
#include "../../utils/assertions.h"

#define VK_ASSERT(expr) {           \
	ASSERT_MSG(expr == VK_SUCCESS)      \
}
#define VK_ASSERT_MSG(expr,msg) {           \
	ASSERT(expr == VK_SUCCESS,msg)          \
}