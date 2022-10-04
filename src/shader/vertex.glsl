#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aNormal;

out vec3 Color;
out vec3 normal;
out vec3 pos;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{
    Color = aColor;
    normal = aNormal;
    pos = aPos;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    /* gl_Position = vec4(aPos, 1.0); */
}
