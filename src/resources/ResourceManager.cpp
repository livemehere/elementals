#include "ResourceManager.h"

#include "../rendering/mesh/primitives/PrimitiveMeshes.h"

const Mesh & ResourceManager::getPlaneMesh() {
    if (!planeMesh_) {
        auto [vertices, indices] = PrimitiveMeshes::createPlane();
        planeMesh_ = std::make_unique<Mesh>(vertices, indices);
    }
    return *planeMesh_;
}

const Mesh & ResourceManager::getCubeMesh() {
    if (!cubeMesh_) {
        auto [vertices, indices] = PrimitiveMeshes::createCube();
        cubeMesh_ = std::make_unique<Mesh>(vertices, indices);
    }
    return *cubeMesh_;
}
