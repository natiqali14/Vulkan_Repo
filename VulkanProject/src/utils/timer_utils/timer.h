#include "../../defines.h"
// initializing all variables used for funtions mentioned below.
bool initialize_timer_subsystem();
/*Simple timer functions using for std::chrono*/
void initialize_starting_time();
u64 get_time_in_microseconds();
u64 get_time_in_miliseconds();
f64 get_time_in_seconds();

/* sleep function with miinimum timer resolution for accurate sleep.
   used for limiting frame rate if frame time < 1/max_fps.
   With this give give back timer to the os.*/
void sleeper(DWORD milli_seconds);