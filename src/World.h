#pragma once

#include <vector>
#include <glad/glad.h>

#include <glm/glm.hpp>

#include "rendering/mesh/Mesh.h"
#include "graphics/Shader.h"
#include "graphics/Texture2D.h"
#include "rendering/mesh/MeshRenderer.h"
#include "rendering/mesh/MeshRenderObject.h"
#include "rendering/mesh/materials/BasicMaterial.h"
#include "resources/ResourceManager.h"

constexpr std::array<uint8_t,4> pixels = {
    255,255,255,255,
};

class World {
private:
    ResourceManager& resourceManager_;

    Shader shader{"shaders/basic.vert", "shaders/basic.frag"};
    Texture2D texture{1,1,pixels};
    BasicMaterial white{shader,texture};
    BasicMaterial green{shader,texture, {0.2f, 0.5f, 0.1f,1.0f}};
    BasicMaterial orange{shader,texture, {1.0f, 0.5f, 0.3f,1.0f}};

    MeshRenderer meshRenderer;
    std::vector<MeshRenderObject> meshObjects;

public:
    World(ResourceManager& resourceManager);
    ~World() = default;

    void update(float dt);
    void render(const RenderContext& context);
};
