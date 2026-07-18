#include "MeshRenderer.h"

void MeshRenderer::render(const RenderContext &context, const MeshRenderObject &object) const {
    const glm::mat4 model = object.transform.getModelMatrix();
    object.material->bind();

    // common uniforms
    object.material->shader.setMat4("uView",context.view);
    object.material->shader.setMat4("uProjection",context.projection);
    object.material->shader.setMat4("uModel", model);
    object.mesh.draw();
}
