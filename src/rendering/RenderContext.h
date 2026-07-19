#pragma once

#include <glm/glm.hpp>

struct AmbientLight {
    glm::vec3 color;
    float intensity;
};

struct RenderContext {
    const glm::mat4& view;
    const glm::mat4& projection;
    const AmbientLight& ambientLight;
};
