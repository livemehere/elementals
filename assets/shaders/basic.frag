#version 410 core

struct AmbientLight {
   vec3 color;
   float intensity;
};

in vec2 vTexCoord;
in vec3 vNormal;

out vec4 FragColor;

uniform AmbientLight ambientLight;

uniform sampler2D uTexture;
uniform vec4 uColor;

void main()
{
    vec3 ambientLightColor = vec3(1.0, 1.0, 1.0);
    float ambientStrength = 0.5;
    vec4 ambient = vec4(ambientLight.color * ambientLight.intensity, 1.0);

    FragColor = texture(uTexture, vTexCoord) * uColor * ambient;
    /** for normal direction debug */
//     FragColor = vec4(vNormal * 0.5 + 0.5, 0.8);
}