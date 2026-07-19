#pragma once
#include "../Scene.h"
#include "mesh/MeshRenderer.h"

namespace UniformBinding {
    constexpr GLuint Camera = 0;
}

struct alignas(16) GPUCameraData {
   glm::mat4 viewMatrix;
   glm::mat4 projectionMatrix;
   glm::vec4 position; // xyz
};

class Renderer {
    MeshRenderer meshRenderer;

    GLuint cameraUBO = 0;

    void updateCameraBuffer(Camera& camera, const WindowSize& windowSize);
public:
    Renderer();
    ~Renderer() {
        if (cameraUBO != 0) {
            glDeleteBuffers(1, &cameraUBO);
        }
    }
    void beginFrame(Camera& camera, const WindowSize& windowSize);
    void render(const Scene& scene);
    void endFrame();
};
