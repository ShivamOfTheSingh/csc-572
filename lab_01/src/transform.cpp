#include "transform.h"
#include <glm/gtc/matrix_transform.hpp>

Transform::Transform()
    : position(0.0f, 0.0f, 0.0f),
      rotation(0.0f, 0.0f, 0.0f),
      scale(1.0f, 1.0f, 1.0f)
{
}

void Transform::setPosition(const glm::vec3 &pos)
{
    position = pos;
}

void Transform::setRotation(const glm::vec3 &rot)
{
    rotation = rot;
}

void Transform::setScale(const glm::vec3 &scl)
{
    scale = scl;
}

glm::vec3 Transform::getPosition() const
{
    return position;
}

glm::vec3 Transform::getRotation() const
{
    return rotation;
}

glm::vec3 Transform::getScale() const
{
    return scale;
}

glm::mat4 Transform::getMatrix() const
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, position);

    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    model = glm::scale(model, scale);

    return model;
}
