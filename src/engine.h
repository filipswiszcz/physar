#ifndef __ENGINE_H__
#define __ENGINE_H__

#ifdef __APPLE__
    //..
#else
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include "math.h"

#define ENGINE_WINDOW_WIDTH 1920 // px
#define ENGINE_WINDOW_HEIGHT 1080
#define ENGINE_WINDOW_NAME "ENGINE (Build v0.0.1)"

#define ENGINE_CYBERSPACE_WIDTH 1000 // mm
#define ENGINE_CYBERSPACE_HEIGHT 1000
#define ENGINE_CYBERSPACE_DEPTH 1000

typedef struct {
    uint32_t width, height, depth;
} Cyberspace_t;

typedef struct {
    Cyberspace_t cyberspace;
    GLFWwindow *window;
    uint32_t width, height;
    std::string name;
} Platform_t;

class Engine {
public:
    void initialize();
    void update();
    void terminate();
private:
    Platform_t platform;
};

#endif // !__ENGINE_H__