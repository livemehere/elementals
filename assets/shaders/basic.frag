#version 410 core

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vPos;

out vec4 FragColor;

uniform sampler2D uTexture;
uniform vec4 uColor;
uniform vec3 uViewPos;

// temp
uniform vec3 uLightPos;
vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightIntensity = 0.5;
float specularIntensity = 0.5;

void main()
{
    vec3 normal = normalize(vNormal);

    // Phong Light
    vec3 lightDir = normalize(uLightPos - vPos);
    vec3 viewDir = normalize(uViewPos - vPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    vec4 ambient = vec4(lightColor * lightIntensity, 1.0);
    float diffuse = max(dot(normal, lightDir),0);

    float spec = pow(max(dot(viewDir, reflectDir),0.0),32);
    vec4 specular = vec4(specularIntensity * spec * lightColor, 1.0);

    FragColor = texture(uTexture, vTexCoord) * uColor * (ambient + diffuse + specular);
    /** for normal direction debug */
//     FragColor = vec4(vNormal * 0.5 + 0.5, 0.8);
}