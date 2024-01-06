#include "Transform.h"

namespace GEPEngine
{
    Transform::Transform()
    {
        Scale = glm::vec3(1);
        Position = glm::vec3(0);
        Rotation = glm::vec3(0);
        
        angle = 10;
    }

    glm::mat4 Transform::getModel()
    {
        glm::mat4 rtn = glm::translate(glm::mat4(1), Position);

        rtn = glm::rotate(rtn, glm::radians(Rotation.x), glm::vec3(1, 0, 0));
        rtn = glm::rotate(rtn, glm::radians(Rotation.y), glm::vec3(0, 1, 0));
        rtn = glm::rotate(rtn, glm::radians(Rotation.z), glm::vec3(0, 0, 1));

        rtn = glm::scale(rtn, Scale);

        return rtn;
    }


    void Transform::Move(glm::vec3 _pos)
    {
        Position += _pos;
    }

    void Transform::Rotate(glm::vec3 _rot)
    {
        Rotation += _rot;
    }

    
}
