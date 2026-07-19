#include "MeshRenderer.h"

void MeshRenderer::render(const RenderContext &context, const MeshRenderObject &object) const {
    const glm::mat4 model = object.transform.getModelMatrix();
    object.material->bind();

    // light
    object.material->shader.setVec3("ambientLight.color",context.ambientLight.color);
    object.material->shader.setFloat("ambientLight.intensity",context.ambientLight.intensity);


    // common uniforms

    object.material->shader.setMat4("uView",context.view);
    object.material->shader.setMat4("uProjection",context.projection);
    object.material->shader.setMat4("uModel", model);
    object.mesh->draw();
}
