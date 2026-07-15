#version 410 core


out vec4 FragColor;

uniform sampler2D uTexture;

void main()
{
    FragColor = texture(uTexture,vec2(1.0, 1.0));
}