#pragma once

// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

#include "math_util.hpp"

// windowing
#include <GLFW/glfw3.h>

class Camera {
public:
  Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 up, float speed,
         float mouse_sensitivity, float fov, GLFWwindow *window,
         unsigned int shader);

  void process_input(GLFWwindow *window, float delta);
  void mouse_callback(double xpos, double ypos);
  void update();

  float pitch;
  float yaw;

  glm::vec3 direction();

private:
  // config stuff
  float m_speed;
  float m_mouse_sensitivity;
  float m_fov;
  bool m_wireframe;

  // 2D window stuff
  float m_last_mouse_x = (float)(1920 / 2);
  float m_last_mouse_y = (float)(1080 / 2);

  // 3D stuff
  glm::vec3 m_position;
  glm::vec3 m_front;
  glm::vec3 m_up;

  glm::mat4 m_view_matrix;
  glm::mat4 m_projection_matrix;

  // shader stuff
  unsigned int m_model_matrix_location;
  unsigned int m_view_matrix_location;
  unsigned int m_projection_matrix_location;
};
