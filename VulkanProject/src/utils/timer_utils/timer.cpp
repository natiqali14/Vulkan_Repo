#include "timer.h"
#include <chrono>
#include "../logger.h"
#define TIMER_RESOLUTION 1

static auto starting_time = std::chrono::high_resolution_clock::now();
static UINT wTimerRes = -1;
bool initialize_timer_subsystem()
{
	initialize_starting_time();
	TIMECAPS tc;
	if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
	{
		log_msg_fatal(stderr, "Timer subsystem initialization failed");
		return false;
	}
	wTimerRes = tc.wPeriodMin > TIMER_RESOLUTION ? tc.wPeriodMin : TIMER_RESOLUTION;
}
void initialize_starting_time()
{
	starting_time = std::chrono::high_resolution_clock::now();
}
u64 get_time_in_microseconds()
{
	auto time = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::microseconds>(time - starting_time).count();
}

u64 get_time_in_miliseconds()
{
	auto time = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::milliseconds>(time - starting_time).count();
}

f64 get_time_in_seconds()
{
	auto time = std::chrono::high_resolution_clock::now();

	return static_cast<f64>( std::chrono::duration_cast<std::chrono::seconds>(time - starting_time).count());
}

void sleeper(DWORD milli_seconds)
{
	timeBeginPeriod(wTimerRes);
	Sleep(milli_seconds);
	timeEndPeriod(wTimerRes);
}
