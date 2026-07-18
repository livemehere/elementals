#pragma once
#include <memory>

#include "../rendering/mesh/Mesh.h"


class ResourceManager {
    std::unique_ptr<Mesh> planeMesh_;
    std::unique_ptr<Mesh> cubeMesh_;
public:
    const Mesh& getPlaneMesh();
    const Mesh& getCubeMesh();
};
