#pragma once
#include <memory>

#include "../rendering/mesh/Mesh.h"


class ResourceManager {
    std::unique_ptr<Mesh> planeMesh_;
public:
    const Mesh& getPlaneMesh();
};
