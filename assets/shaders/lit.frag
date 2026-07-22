#version 410 core

#define MAX_POINT_LIGHTS 16
#define MAX_DIRECTIONAL_LIGHTS 4

layout (std140) uniform CameraData {
    mat4 view;
    mat4 projection;
    vec4 position;
} camera;

struct DirectionalLight {
    // xyz, w(x)
    vec4 direction;
    // rgb, w
    vec4 colorIntensity;
};

struct PointLight {
    // xyz, w
    vec4 positionRange;
    // rgb, w
    vec4 colorIntensity;
};

layout (std140) uniform LightsData {
    // rgb : color
    // w : intensity
    vec4 ambientLightColorIntensity;

    // x: directionalLight / y : pointLight
    ivec4 lightCounts;
    DirectionalLight directionalLights[MAX_DIRECTIONAL_LIGHTS];
    PointLight pointLights[MAX_POINT_LIGHTS];
} lights;

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vPos;

struct Material {
    sampler2D albedo;
    sampler2D specular;
    int hasSpecularMap;
    vec4 baseColor;
    float shininess;
    float specularStrength;
};

uniform Material material;

out vec4 FragColor;

vec3 calculateAmbient(vec3 albedo)
{
    vec3 color = lights.ambientLightColorIntensity.rgb;
    float intensity = lights.ambientLightColorIntensity.w;
    return albedo * color * intensity;
}

vec3 calculatePointLight(PointLight light, vec3 albedo, vec3 normal, vec3 viewDir)
{
    /** diffuse */
    vec3 color = light.colorIntensity.rgb;
    float intensity = light.colorIntensity.w;

    vec3 position = light.positionRange.rgb;
    float range = light.positionRange.w;
    vec3 toLight = position - vPos;
    float distance = length(toLight);

    if(distance > range){
        return vec3(0.0);
    }

    vec3 lightDir = toLight / max(distance, 0.0001);
    float diffuseFactor = max(dot(normal, lightDir), 0);
    float distanceNormal = distance / range;
    float attenuation = 1.0 - smoothstep(0.0, 1.0, distanceNormal);

    vec3 diffuse = albedo * color * intensity * diffuseFactor * attenuation;

    /** specular */
    vec3 reflectDir = reflect(-lightDir, normal);
    float specularAngle = max(dot(viewDir, reflectDir),0.0);
    float specularFactor = pow(specularAngle, material.shininess);

    float specularMask = 0.0;
    vec3 specular = color * intensity * attenuation * specularFactor * material.specularStrength;
    if(material.hasSpecularMap != 0){
       specularMask = texture(material.specular,vTexCoord).r;
    }

    return diffuse + specular * specularMask;
}

void main()
{
    vec4 textureColor = texture(material.albedo, vTexCoord);
    vec3 albedo = textureColor.rgb * material.baseColor.rgb;

    /** ambient light */
    vec3 result = calculateAmbient(albedo);

    /** point lights */
    vec3 normal = normalize(vNormal);
    vec3 viewDir = normalize(camera.position.xyz - vPos);
    int pointLightCount = min(lights.lightCounts.y,MAX_POINT_LIGHTS);
    for(int i=0; i<pointLightCount; i++){
       result += calculatePointLight(lights.pointLights[i], albedo, normal, viewDir);
    }

    float alpha = textureColor.a * material.baseColor.a;
    FragColor = vec4(result, alpha);
    /** for normal direction debug */
//     FragColor = vec4(vNormal * 0.5 + 0.5, 0.8);
}