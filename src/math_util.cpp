#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>

namespace util
{
    glm::vec3 eulerToVector(float pitch, float yaw)
    {
        glm::vec3 direction;
        direction.x = std::cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = -std::sin(glm::radians(pitch));
        direction.z = std::sin(glm::radians(yaw)) * cos(glm::radians(pitch));

        return direction;
    }
}
