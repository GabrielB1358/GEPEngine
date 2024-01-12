#include "Transform.h"
#include <iostream>
namespace GEPEngine
{
    Transform::Transform()
    {
        //Default values for fundamental variables
        m_scale = glm::vec3(1);
        m_position = glm::vec3(0);
        m_rotation = glm::vec3(0);
        m_velocity = glm::vec3(0);
        m_lastTickPosition = glm::vec3(0,10,0);
        
        m_angle = 10;
    }

    glm::mat4 Transform::getModel()
    {
        //this function creates and returns a model matrix using the position, rotation & scale
        glm::mat4 rtn = glm::translate(glm::mat4(1), m_position);

        rtn = glm::rotate(rtn, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
        rtn = glm::rotate(rtn, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
        rtn = glm::rotate(rtn, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));

        rtn = glm::scale(rtn, m_scale);

        return rtn;
    }

    void Transform::onTick()
    {

    }

    void Transform::endFrame()
    {
        //Updates last tick position for use in collision testing
        m_lastTickPosition = m_position;
    }

    void Transform::Move(glm::vec3 _pos)
    {
        m_position += _pos;
    }

    void Transform::Rotate(glm::vec3 _rot)
    {
        m_rotation += _rot;
    }

    glm::vec3 Transform::getPosition()
    {
        return m_position;
    }

    glm::vec3 Transform::getScale()
    {
        return m_scale;
    }
    
    glm::vec3 Transform::getRotation()
    {
        return m_rotation;
    }

    glm::vec3 Transform::getVelocity()
    {
        return m_velocity;
    }

    glm::vec3 Transform::getLastTickPos()
    {
        return m_lastTickPosition;
    }

    int Transform::getAngle()
    {
        return m_angle;
    }

    void Transform::setPosition(glm::vec3 _pos)
    {
        m_position = _pos;
    }

    void Transform::setLastTickPos(glm::vec3 _pos)
    {
        m_lastTickPosition = _pos;
    }

    void Transform::setVelocity(glm::vec3 _vel)
    {
        m_velocity = _vel;
    }

    void Transform::setScale(glm::vec3 _scale)
    {
        m_scale = _scale;
    }

    void Transform::setRotation(glm::vec3 _rot)
    {
        m_rotation = _rot;
    }

    void Transform::setAngle(int _angle)
    {
        m_angle = _angle;
    }
}
