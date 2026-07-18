#include "MeshRenderer.h"

void MeshRenderer::render(const RenderContext &context, const MeshRenderObject &object) const {
    const glm::mat4 model = object.transform.getModelMatrix();
    object.material->bind({
        .view = context.view,
        .projection = context.projection
    });
    object.material->shader.setMat4("uModel", model);
    object.mesh->draw();

}
