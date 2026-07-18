#include "BasicMaterial.h"

void BasicMaterial::bind(const RenderContext& context) const {
    shader.use();

    // this material
    texture.bind(0);
    shader.setInt("uTexture",0);
    shader.setVec4("uColor",color);

    // common uniforms
    shader.setMat4("uModel",context.model);
    shader.setMat4("uView",context.view);
    shader.setMat4("uProjection",context.projection);
}
