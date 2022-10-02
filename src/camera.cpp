// math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

#include "math_util.hpp"

// (modern) OpenGL
#include <GL/glew.h>

// windowing
#include <GLFW/glfw3.h>

// Camera class
#include "camera.hpp"

// config
#include "config.h"

#include <iostream>

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 up,
               float speed, float mouse_sensitivity, float fov,
               GLFWwindow *window, unsigned int shader) {
  m_wireframe = false;

  this->pitch = pitch;
  this->yaw = yaw;

  this->m_position = position;
  this->m_front = direction();
  this->m_up = up;
  this->m_speed = speed;
  this->m_mouse_sensitivity = mouse_sensitivity;
  this->m_fov = fov;

  m_view_matrix_location = glGetUniformLocation(shader, "view");
  m_projection_matrix_location = glGetUniformLocation(shader, "projection");

  /* this->m_view_matrix = glm::lookAt(position, position + m_front, up); */
  /* this->m_projection_matrix = */
  /*     glm::perspective(glm::radians(fov), (float)SCREEN_WIDTH /
   * (float)SCREEN_HEIGHT, 0.1f, 100.0f); */
  update();
}

void Camera::update() {
  m_view_matrix = glm::lookAt(m_position, m_position + m_front, m_up);
  m_projection_matrix = glm::perspective(
      glm::radians(m_fov), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f,
      100.0f);

  /* this->projectionMatrix = glm::mat4(1.0f); */
  /* this->viewMatrix = glm::mat4(1.0f); */

  if (m_wireframe)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glUniformMatrix4fv(m_view_matrix_location, 1, GL_FALSE,
                     glm::value_ptr(m_view_matrix));
  glUniformMatrix4fv(m_projection_matrix_location, 1, GL_FALSE,
                     glm::value_ptr(m_projection_matrix));
}

void Camera::process_input(GLFWwindow *window, float delta) {
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    m_position += m_front * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    m_position -= m_front * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    m_position -= glm::normalize(glm::cross(m_front, m_up)) * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    m_position += glm::normalize(glm::cross(m_front, m_up)) * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    m_position += m_up * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    m_position -= m_up * m_speed * delta;

  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    m_speed += 5.0 * delta;

  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    m_speed -= 5.0 * delta;

  /* if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS) */
  /*   m_wireframe = true; */
  /* else */
  /*   m_wireframe = false; */
  m_wireframe = glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS;
}

glm::vec3 Camera::direction() { return util::eulerToVector(pitch, yaw); }

void Camera::mouse_callback(double x_pos, double y_pos) {
  float x_offset = x_pos - m_last_mouse_x;
  float y_offset = y_pos - m_last_mouse_y;

  m_last_mouse_x = x_pos;
  m_last_mouse_y = y_pos;

  yaw += x_offset * m_mouse_sensitivity;
  pitch += y_offset * m_mouse_sensitivity;

  pitch = util::clamp<float>(-89.0f, 89.0f, pitch);

  m_front = direction();
}
