#pragma once
#include "../defines.h"
#include "../FrontEnd/GLFW_Window.h"
enum class EEngineState : u8 {
	EES_NOT_INITIALIZED,
	EES_READY,
	EES_RUNNING,
	EES_STOPPED,
};
typedef struct engine_data {
	/* Current delta time microseconds/frame of engine.*/
	u64 delta_time = 0;
	/* With this we calculate our frame_time (total time for a frame)  */
	u16 max_fps = 60;
	/* With the max fps we caclculate total frame time*/
	u64 frame_time;

};
class Engine
{
	/**
	* Time in this project will be in microseconds by default for calculations purpose
	*/
	// main window pointer
	GLFW_Window* main_window;
	EEngineState state;
	static Engine* instace;
	engine_data internal_data;
	const char* engine_name;
	Engine();
	
public:
	Engine(Engine& obj) = delete;
	Engine& operator=(const Engine&) = delete;
	static Engine* get_engine();
	bool initiate_engine();
	void engine_run();
	void stop_engine();
	~Engine();

	
	

};

