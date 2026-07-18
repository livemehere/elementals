#pragma once

#include "Material.h"
#include "../../../graphics/Texture2D.h"


class BasicMaterial : public Material {
public:
    glm::vec4 tint = {1.0f,1.0f,1.0f,1.0f};
    const Texture2D& texture;

    BasicMaterial(const Shader &shader, const Texture2D& texture)
        : Material(shader), texture(texture) {}

    ~BasicMaterial() override = default;

    void bind(const RenderContext& context) override;
};
