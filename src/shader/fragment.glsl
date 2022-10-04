#version 330 core

out vec4 FragColor;

in vec3 Color;
in vec3 normal;
in vec3 pos;

void main()
{
    float angle = dot(normal, normalize((vec3(-30.0f, 50.0f, 30.0f) - pos)));
    float ground_light = 0.5f;
    float dynamic_light = (1.0f - ground_light) * angle;
    dynamic_light = max(0, dynamic_light);
    FragColor = vec4(Color * (ground_light + dynamic_light), 1.0);
}
