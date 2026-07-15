#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 uModel;
uniform mat4 uView;

out vec2 vTexCoord;

void main()
{
    gl_Position = uView * uModel * vec4(aPos, 1.0);
    vTexCoord = aTexCoord;
}