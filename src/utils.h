#pragma once

#include <fstream>
#include <string>
#include <sstream>

#include "opengl/Shader.h"

namespace utils {

    inline std::filesystem::path asset_path(
        const std::string &filepath) {
        return  std::filesystem::path(ASSET_ROOT) / filepath;
    }

    inline std::string read_file(const std::string& filepath) {
        std::ifstream file(filepath);

        if (!file.is_open()) {
            throw std::runtime_error(std::format("Failed to open file : {}", filepath));
        }

        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }

    inline GLuint create_shader_program(const std::string& vsPath, const std::string& fsPath) {
        // TODO: convert shader to RAII to cleanup each stage.
        // if vs compile success and fs failed then vs doesn't cleanup it self.
        Shader vs = Shader(GL_VERTEX_SHADER,vsPath);
        Shader fs = Shader(GL_FRAGMENT_SHADER,fsPath);

        GLuint program = glCreateProgram();
        glAttachShader(program, vs.getId());
        glAttachShader(program, fs.getId());
        glLinkProgram(program);

        GLint success = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        glDeleteShader(vs.getId());
        glDeleteShader(fs.getId());

        if (success == GL_TRUE) {
            return program;
        }

        // failed case
        GLint logLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength,'\0');

        GLsizei written = 0;
        glGetProgramInfoLog(program, logLength, &written, log.data());
        log.resize(written);

        throw std::runtime_error(std::format("[SHADER_PROGRAM] {}", log));
    }

}
