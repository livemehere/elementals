#pragma once

#include "../opengl/Mesh.h"
#include "../common.h"

class RenderObject {
public:
    Transform transform;
    Mesh* mesh;

};
