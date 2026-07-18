#include "ResourceManager.h"

#include "../rendering/mesh/primitives/PrimitiveMeshes.h"

const Mesh & ResourceManager::getPlaneMesh() {
    if (!planeMesh_) {
        auto [vertices, indices] = PrimitiveMeshes::createPlane();
        planeMesh_ = std::make_unique<Mesh>(vertices, indices);
    }
    return *planeMesh_;
}
