#pragma once

#include <vector>
#include "camera/Camera.h"
#include "rendering/mesh/MeshRenderObject.h"

class Scene {
public:
    Camera camera;
    std::vector<MeshRenderObject> meshObjects;

    Scene() = default;
    ~Scene() = default;

    void update(float dt);
};
