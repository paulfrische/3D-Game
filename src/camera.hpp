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

class Camera
{
    public:
        Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 up, float speed, float mouse_sensitivity, float fov, GLFWwindow* window, unsigned int shader);

        void processInput(GLFWwindow* window, float delta);
        void mouse_callback(double xpos, double ypos);
        void Update();

        float pitch;
        float yaw;

        glm::vec3 direction();

    private:
        
        // config stuff
        float speed;
        float mouse_sensitivity;
        float fov;
        bool wireframe;

        // 2D window stuff
        float lastMouseX = (float)(1920 / 2);
        float lastMouseY = (float)(1080 / 2);

        // 3D stuff
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;

        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;

        // shader stuff
        unsigned int modelMatrixLocation;
        unsigned int viewMatrixLocation;
        unsigned int projectionMatrixLocation;
};
