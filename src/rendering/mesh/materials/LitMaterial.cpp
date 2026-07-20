#include "LitMaterial.h"

void LitMaterial::bind() const {
    shader.use();

    // this material
    albedoTexture.bind(0);
    shader.setInt("material.albedoTexture",0);
    shader.setVec4("material.baseColor",baseColor);
    shader.setFloat("material.shininess",shininess);
    shader.setFloat("material.specularStrength",specularStrength);
}
