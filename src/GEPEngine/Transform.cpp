#include "Transform.h"

namespace GEPEngine
{
    Transform::Transform() : rotation(0)
    {

    }

    glm::mat4 Transform::getModel(glm::vec3 _rot)
    {
        glm::mat4 rtn = glm::translate(glm::mat4(1), Position);

        rtn = glm::rotate(rtn, glm::radians(_rot.x), glm::vec3(1, 0, 0));
        rtn = glm::rotate(rtn, glm::radians(_rot.y), glm::vec3(0, 1, 0));
        rtn = glm::rotate(rtn, glm::radians(_rot.z), glm::vec3(0, 0, 1));

        return rtn;
    }

    void Transform::Move(glm::vec3 _pos)
    {
        Position += _pos;
    }
}
