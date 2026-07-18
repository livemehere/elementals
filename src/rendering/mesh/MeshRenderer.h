#pragma once
#include "MeshRenderObject.h"
#include "../RenderContext.h"


class MeshRenderer {
public:
    MeshRenderer() = default;
    ~MeshRenderer() = default;

    void render(const RenderContext &context, const MeshRenderObject &object) const;
};
