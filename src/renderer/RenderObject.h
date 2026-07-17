#pragma once

#include "Mesh.h"
#include "../common.h"
#include "../graphics/Shader.h"
#include "../graphics/Texture2D.h"

struct RenderObject {
    Transform transform;
    Mesh* mesh;
    Shader* shader;
    Texture2D* texture;
};
