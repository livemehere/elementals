#pragma once

#include <string>
#include <glad/glad.h>

class ShaderStage {
    GLuint id_ = 0;
public:
    ShaderStage(GLenum type, const std::string &filepath);
    ~ShaderStage() {
        if (id_ != 0) {
            glDeleteShader(id_);
        }
    }

    ShaderStage(const ShaderStage&) = delete;
    ShaderStage& operator=(const ShaderStage&) = delete;

    GLuint getId() const { return id_; }
};
