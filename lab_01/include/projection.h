#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Projection
{
public:
    // Default constructor
    Projection();

    // Set perspective projection parameters
    void setPerspective(float fovDegrees, float aspect, float nearPlane, float farPlane);

    // Set orthographic projection parameters
    void setOrthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane);

    // Get the current projection matrix
    const glm::mat4 &getMatrix() const;

private:
    glm::mat4 projMatrix;
};
