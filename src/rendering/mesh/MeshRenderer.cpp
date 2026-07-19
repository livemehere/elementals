#include "MeshRenderer.h"

#include "../Renderer.h"
#include "materials/BasicMaterial.h"

void MeshRenderer::render(const MeshRenderObject &object) const {

    object.material->shader.bindUniformBlock("CameraData", UniformBinding::Camera);
    object.material->shader.bindUniformBlock("LightsData", UniformBinding::Lights);

    const glm::mat4 model = object.transform.getModelMatrix();
    object.material->bind();

    // ambient light
    // object.material->shader.setVec3("uLightPos",context.lightPos);
    // object.material->shader.setVec3("uViewPos",context.viewPos);
    object.material->shader.setMat4("uModel", model);
    object.mesh->draw();
}
