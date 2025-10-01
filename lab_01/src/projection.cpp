#include "projection.h"

Projection::Projection()
{
    // initialize to identity by default
    projMatrix = glm::mat4(1.0f);
}

void Projection::setPerspective(float fovDegrees, float aspect, float nearPlane, float farPlane)
{
    // glm::perspective expects FOV in radians
    projMatrix = glm::perspective(glm::radians(fovDegrees), aspect, nearPlane, farPlane);
}

void Projection::setOrthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
    projMatrix = glm::ortho(left, right, bottom, top, nearPlane, farPlane);
}

const glm::mat4 &Projection::getMatrix() const
{
    return projMatrix;
}
