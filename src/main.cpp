#include <iostream>

// use (modern) OpenGL
#define GLEW_STATIC
#include <GL/glew.h>

// windowing and input
#include <GLFW/glfw3.h>

// utilities for creating windows etc.
#include "util.hpp"
#include "shader_s.hpp"

// image loading
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

struct vertex {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
};

vertex vertices[] = {
    vertex { -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f },
    vertex {  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f },
    vertex {  0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f },
};

int main(int argc, char** argv)
{
    GLFWwindow* window = setup();

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int shader = make_program("./src/shader/vertex.glsl", "./src/shader/fragment.glsl");
    glUseProgram(shader);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 3, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    terminate();
}
