#include "Shader.h"

#include <format>
#include <stdexcept>

#include "ShaderStage.h"

Shader::Shader(const std::string &vsPath, const std::string &fsPath) {
    const ShaderStage vs(GL_VERTEX_SHADER,vsPath);
    const ShaderStage fs(GL_FRAGMENT_SHADER,fsPath);

    id_ = glCreateProgram();
    glAttachShader(id_, vs.getId());
    glAttachShader(id_, fs.getId());
    glLinkProgram(id_);

    GLint success = GL_FALSE;
    glGetProgramiv(id_, GL_LINK_STATUS, &success);

    if (success == GL_FALSE) {
        GLint logLength = 0;
        glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength,'\0');

        GLsizei written = 0;
        glGetProgramInfoLog(id_, logLength, &written, log.data());
        log.resize(written);
        glDeleteProgram(id_);

        throw std::runtime_error(std::format("[SHADER_PROGRAM] {}", log));
    }

    glDetachShader(id_, vs.getId());
    glDetachShader(id_, fs.getId());

}

