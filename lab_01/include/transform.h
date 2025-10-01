#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
public:
    Transform();

    void setPosition(const glm::vec3 &pos);
    void setRotation(const glm::vec3 &rot);
    void setScale(const glm::vec3 &scl);

    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale() const;

    glm::mat4 getMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
