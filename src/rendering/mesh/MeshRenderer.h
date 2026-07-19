#pragma once
#include "MeshRenderObject.h"

class MeshRenderer {
public:
    MeshRenderer() = default;
    ~MeshRenderer() = default;

    void render(const MeshRenderObject &object) const;
};
