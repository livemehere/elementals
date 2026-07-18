#pragma once

#include "Mesh.h"
#include "../Transform.h"
#include "materials/Material.h"

struct MeshRenderObject {
    Transform transform = {
        .position = {0.0f,0.0f,0.0f},
        .rotation = {0.0f,0.0f,0.0f},
        .scale = {1.0f,1.0f,1.0f},
    };
    const Mesh* mesh = nullptr;
    const Material* material = nullptr;
};

