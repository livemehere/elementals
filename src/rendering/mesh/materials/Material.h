#pragma once
#include "../../../graphics/Shader.h"
#include "../../RenderContext.h"

class Material {
public:
    const Shader& shader;
    Material(const Shader& shader) : shader(shader) {}

    virtual ~Material() = default;

    virtual void bind (const RenderContext& context) const = 0;
};
