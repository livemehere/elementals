#include "BasicMaterial.h"

void BasicMaterial::bind() const {
    shader.use();

    // this material
    texture.bind(0);
    shader.setInt("uTexture",0);
    shader.setVec4("uColor",color);
}
