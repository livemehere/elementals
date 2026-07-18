#include "../../mesh/primitives/PrimitiveMeshes.h"

namespace PrimitiveMeshes {
    MeshData createPlane() {
        return {
            .vertices = {
                {{ -0.5f, -0.5f, 0.0f}, {0.0f,0.0f}}, // left bottom
                {{ 0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}}, // right bottom
                {{ -0.5f, 0.5f, 0.0f}, {0.0f, 1.0f}}, // left top
                {{ 0.5f, 0.5f, 0.0f}, {1.0f, 1.0f}}, // right top
            },
            .indices = {
                0, 1, 2,
                1, 3, 2
            }
        };
    }
}
