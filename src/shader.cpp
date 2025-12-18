#include "shader.h"

// public

void renderer::Shader::create_program(std::string paths[2]) {
    std::string vs_code = this->read_file(paths[0]);
    std::string fs_code = this->read_file(paths[1]);

    // null code asserts

    this->ids[0] = this->compile(GL_VERTEX_SHADER, vs_code);
    this->ids[1] = this->compile(GL_FRAGMENT_SHADER, fs_code);

    this->program = glCreateProgram();
    glAttachShader(this->program, this->ids[0]);
    glAttachShader(this->program, this->ids[1]);

    glLinkProgram(this->program);

    // int32_t params;
    // glGetShaderiv(*id, GL_COMPILE_STATUS, &params);
    // if (params == 0) {
    //     char log[512]; // c_str()?
    //     glGetShaderInfoLog(*id, 512, NULL, log);
    //     printf("SHADER_COMPILE_ERROR: %s\n", log);
    //     return;
    // }
}

void renderer::Shader::set_vec3(std::string name, Vec3_t vec) {
    glUniform3f(glGetUniformLocation(this->program, name.c_str()), vec.x, vec.y, vec.z);
}

void renderer::Shader::set_mat4(std::string name, Mat4_t mat) {
    glUniformMatrix4fv(glGetUniformLocation(this->program, name.c_str()), 1, 0, &mat.m[0][0]);
}

// private

std::string renderer::Shader::read_file(std::string &path) {
    std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);

    // assert file open

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string code(size, '\0');

    // assert file read

    return code;
}

int32_t renderer::Shader::compile(uint32_t type, std::string &code) {
    int32_t shader = glCreateShader(type);
    const char *source = code.c_str();

    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    return shader;
}