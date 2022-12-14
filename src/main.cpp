#include <iostream>

// use (modern) OpenGL
#define GLEW_STATIC
#include <GL/glew.h>

// windowing and input
#include <GLFW/glfw3.h>

// utilities for creating windows etc.
#include "shader_s.hpp"
#include "util.hpp"

// chunk
#include "chunk.hpp"

// image loading
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

// for sleeping
#include <chrono>
#include <thread>

// camera
#include "camera.hpp"

// vertex
#include "vertex.hpp"

vertex vertices[] = {
    vertex{-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f},
    vertex{0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f},
    vertex{0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f},
};

double mouse_x_position;
double mouse_y_position;

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
  mouse_x_position = xpos;
  mouse_y_position = ypos;
}

int main(int argc, char **argv) {
  GLFWwindow *window = setup();
  glfwSetCursorPosCallback(window, mouse_callback);

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  unsigned int shader =
      make_program("./src/shader/vertex.glsl", "./src/shader/fragment.glsl");
  glUseProgram(shader);

  unsigned int model_matrix_location = glGetUniformLocation(shader, "model");
  /* unsigned int view_matrix_location = glGetUniformLocation(shader, "view");
   */
  /* unsigned int projection_matrix_location = glGetUniformLocation(shader,
   * "projection"); */

  Camera cam(glm::vec3(0.0f, 0.0f, 3.0f), 0.0f, -90.0f,
             glm::vec3(0.0f, 1.0f, 0.0f), 5.0f, 0.01f, 45.0f, window, shader);

  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      blocks{};
  for (int x = 0; x < CH_WIDTH; x++) {
    for (int y = 0; y < CH_HEIGHT; y++) {
      for (int z = 0; z < CH_DEPTH; z++) {
        if (x % 2 == 0)
          blocks[x][y][z] = 1;
      }
    }
  }

  ChunkManager manager(shader);
  manager.generateWorld();
  manager.genVBOs();

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex),
                        (void *)(3 * sizeof(float)));
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(vertex),
                        (void *)(6 * sizeof(float)));

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  float current_frame = glfwGetTime();
  float last_frame = 0.0f;

  glEnable(GL_DEPTH_TEST);

  while (!glfwWindowShouldClose(window)) {
    current_frame = glfwGetTime();
    float delta_time = current_frame - last_frame;
    last_frame = current_frame;

    cam.process_input(window, delta_time);
    cam.mouse_callback(mouse_x_position, mouse_y_position);
    cam.update();

    /* glm::mat4 view_matrix = glm::mat4(1.0f); */
    /* glm::mat4 projection_matrix = glm::mat4(1.0f); */
    /* glUniformMatrix4fv(view_matrix_location, 1, GL_FALSE,
     * glm::value_ptr(view_matrix)); */
    /* glUniformMatrix4fv(projection_matrix_location, 1, GL_FALSE,
     * glm::value_ptr(projection_matrix)); */

    glClearColor(135.0f / 255.0f, 1.0f, 245.0f / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* glDrawArrays(GL_TRIANGLES, 0, 3); */
    manager.render();

    glfwSwapBuffers(window);
    glfwPollEvents();

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
  }

  terminate();
}
