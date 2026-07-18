#include "./PrimitiveMeshes.h"

namespace PrimitiveMeshes {
    MeshData createPlane() {
        const std::vector<Vertex> vertices {
            {{ -0.5f, -0.5f, 0.0f}, {0.0f,0.0f}}, // left bottom
            {{ 0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}}, // right bottom
            {{ -0.5f, 0.5f, 0.0f}, {0.0f, 1.0f}}, // left top
            {{ 0.5f, 0.5f, 0.0f}, {1.0f, 1.0f}}, // right top
        };
        const std::vector<GLuint> indices{
            0, 1, 2,
            1, 3, 2
         };

        return {
            vertices,
            indices
        };
    }
}
