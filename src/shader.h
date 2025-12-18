#ifndef __SHADER_H__
#define __SHADER_H__

#include <fstream>
// #include <string>

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #define GLFW_INCLUDE_GLCOREARB
    #include <GLFW/glfw3.h>
#else
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include "math.h"

namespace renderer {

class Shader {
public:
    int32_t get_program() {return program;}
    void create_program(std::string paths[2]);
    void set_vec3(std::string name, Vec3_t vec);
    void set_mat4(std::string name, Mat4_t mat);
private:
    int32_t ids[2]; // [0] = vert, [1] = frag
    int32_t program;
    std::string read_file(std::string &path);
    int32_t compile(uint32_t type, std::string &code);
};

}

#endif // !__SHADER_H__