#define GLFW_INCLUDE_VULKAN

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
#include "Game/VulkanEngine.h"
#include <chrono>
#include <iostream>
#include "defines.h"
#include "utils/timer_utils/timer.h"
#include "utils/logger.h"

int main() {
   /* glfwInit();
    uint32_t version;
    vkEnumerateInstanceVersion(&version);
    std::cout << "Version supported : " << VK_API_VERSION_VARIANT(version) <<
        " " << VK_API_VERSION_MAJOR(version) << " " << VK_API_VERSION_MINOR(version)
        << " " << VK_API_VERSION_PATCH(version) << std::endl;;
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();*/
   // Engine* e = new Engine();
    //double d = 1.0 / 60.0;
    //uint64_t frame_time = static_cast<uint64_t>(d * 1e6);
    //initialize_starting_time();
    //f64 t1 = get_time_in_seconds();
    //u64 last_time = get_time_in_microseconds();
    //while (true) {
    //    u64 current_time = get_time_in_microseconds();
    //    u64 delta = current_time - last_time; // delta seconds for frame
    //    std::cout << (float)delta /1e6 << '\n';
    //    u64 frame_start_time = get_time_in_microseconds();
    //    // do things
    //    // ----- to be deleted ---------
    //    std::this_thread::sleep_for(std::chrono::milliseconds(180)); // imaginary render_pass
    //    // ----- to be deleted ---------
    //    u64 frame_end_time = get_time_in_microseconds();
    //    if (frame_end_time - frame_start_time < frame_time) {
    //        // give time back to os
    //        std::this_thread::sleep_for(std::chrono::microseconds(frame_time - (frame_end_time - frame_start_time)));
    //    }
    //    last_time = current_time;
    //}
    //
    //f64 t2 = get_time_in_seconds();
    //std::cout << t2 - t1;
   Engine::get_engine()->initiate_engine();
   Engine::get_engine()->engine_run();

   // timeBeginPeriod(1);
   // LARGE_INTEGER frequency;
   // QueryPerformanceFrequency(&frequency);
   // auto f = (f64) 1000000 / frequency.QuadPart;
   // LARGE_INTEGER time;
   //
   // auto t3 = get_time_in_microseconds();
   // QueryPerformanceCounter(&time);

   // f64 t = time.QuadPart * f;
   //// t /= 1e6;
   // Sleep(33);
   // timeEndPeriod(1);
   // LARGE_INTEGER time2;
   // QueryPerformanceCounter(&time2);
   // auto t4 = get_time_in_microseconds();
   // f64 t2 = time.QuadPart * f;
   //// t2 /= 1e6;
   // u64 to =  (time2.QuadPart - time.QuadPart) *f;
   //// to /= 1;
   // log_msg(stderr, "%llu\n", t4 - t3);
   // log_msg(stderr, "%llu", to);
   log_msg_fatal(stderr, "jabaaaaaaaaaaaaaa");
    return 0;
}