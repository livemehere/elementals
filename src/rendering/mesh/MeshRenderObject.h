#pragma once

#include "Mesh.h"
#include "../Transform.h"
#include "materials/Material.h"

struct MeshRenderObject {
    Transform transform;
    const Mesh& mesh;
    Material* material;
};

