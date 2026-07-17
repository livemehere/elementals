#pragma once

#include <iostream>
#include <glm/vec3.hpp>

#define LOG(x) std::cout << x << std::endl;

struct Transform {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};

