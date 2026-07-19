#pragma once

#include <glm/glm.hpp>

struct RenderContext {
    const glm::mat4& view;
    const glm::mat4& projection;
    glm::vec3 lightPos;
};
