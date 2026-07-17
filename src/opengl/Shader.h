#pragma once

#include <string>
#include <glad/glad.h>

class Shader {
    GLuint id_ = 0;
public:
    Shader(const std::string& vsPath, const std::string& fsPath);
    ~Shader() {
        if (id_ != 0) {
            glDeleteProgram(id_);
        }
    }

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void use() const {
        glUseProgram(id_);
    }

    GLuint getId() const { return id_; }
};
