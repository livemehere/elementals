#version 410 core

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vPos;

out vec4 FragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;


// temp
uniform vec3 lightPos;
vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightIntensity = 0.5;


void main()
{
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(lightPos - vPos);

    // Phong Light
    vec4 ambient = vec4(lightColor * lightIntensity, 1.0);
    float diffuse = max(dot(normal, lightDir),0);

    FragColor = texture(uTexture, vTexCoord) * uColor * (ambient + diffuse);
    /** for normal direction debug */
//     FragColor = vec4(vNormal * 0.5 + 0.5, 0.8);
}