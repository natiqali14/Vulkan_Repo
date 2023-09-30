#include "VulkanEngine.h"
#include "../utils/logger.h"
#include "../utils/timer_utils/timer.h"
#include "../Renderer_Api/renderer_frontend.h"
#include<windows.h>
Engine* Engine::instace = nullptr;
Engine::Engine()
{
	state = EEngineState::EES_NOT_INITIALIZED;
    main_window = nullptr;
}

Engine* Engine::get_engine()
{
	if (instace) return instace;
	instace = new Engine();
	return instace;
}

bool Engine::initiate_engine()
{
    // Setting Egines ouwn data
    // 0.

	/* This is where we should initialze all of our sub-system */
	// 1. windowing
	main_window = new GLFW_Window(800, 600, "Game Window");
	if (!main_window) return false;
	if (!(main_window->get_window())) return false;

    // 2. Timer subsystem
    if(!initialize_timer_subsystem()) return false;
    
    // 3.  Renderer
    if (!renderer_initialize(engine_name, internal_data)) return false;

	// after all subsystems are ready
	state = EEngineState::EES_READY;
    return true;
}

void Engine::engine_run()
{
    if (state != EEngineState::EES_READY) {
        log_msg_fatal(stderr, "Engine not ready");
        return;
    }
    initialize_starting_time();
    f64 d = 1.0 / internal_data.max_fps; // 60
    internal_data.frame_time = static_cast<u64>(d * 1e6);
    u64 last_time = get_time_in_microseconds();
    while (!main_window->should_window_close()) {
        u64 current_time = get_time_in_microseconds();
        u64 delta = current_time - last_time; // delta seconds for frame in micro seconds for accuracy
        internal_data.delta_time = delta;
        u64 frame_start_time = get_time_in_microseconds();

        // do things
        // ----- to be deleted ---------
        render_packet* packet = (render_packet*) malloc(sizeof(render_packet));
        packet->delta_time = delta;
        //sleeper(5);
        // ----- to be deleted ---------

        u64 frame_end_time = get_time_in_microseconds();

        if ((frame_end_time - frame_start_time) < internal_data.frame_time) {
            // give time back to os
            sleeper((internal_data.frame_time - (frame_end_time - frame_start_time)) / 1e3);
        }
       /* else {

            f64 seconds = (((frame_end_time - frame_start_time) / 1e6));
        }*/
        free(packet);
        last_time = current_time; // this should be the last line after all calculations
        u64 fps = 1e6 / internal_data.delta_time;
        

       /// log_msg_fatal(stderr, "%llu\n", fps);
    }
}

void Engine::stop_engine()
{
}

Engine::~Engine()
{
	log_msg(stdout, "Engine Destructed");
}


