#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

#include "math_util.tcc"

namespace util
{
    glm::vec3 eulerToVector(float pitch, float yaw);
}
