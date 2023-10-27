#include "Transform.h"

namespace GEPEngine
{
    Transform::Transform() : rotation(0)
    {

    }

    void Transform::Rotate(glm::vec3 _rot, float angle)
    {
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0, -10));
        rotation += 0.5f;
        rotMat = glm::rotate(rotMat, glm::radians(angle), _rot);
    }





    glm::mat4 Transform::getRotMat()
    {
        return rotMat;
    }

    glm::vec3 Transform::getPos()
    {
        return Position;
    }

    glm::vec3 Transform::getScale()
    {
        return Scale;
    }

    void Transform::setRot(glm::vec3 _rot)
    {
        Rotation = _rot;
    }

    void Transform::setPos(glm::vec3 _pos)
    {
        Position = _pos;
    }

    void Transform::setScale(glm::vec3 _scale)
    {
        Scale = _scale;
    }
}
