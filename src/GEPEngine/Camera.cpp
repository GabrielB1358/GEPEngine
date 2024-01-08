#include "Camera.h"
#include <GEPEngine/MouseInput.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GEPEngine
{

	void Camera::initialise()
	{
		m_cameraPos = glm::vec3(0.0f, 8.0f, 17.0f);
		glm::vec3 initTarget = glm::vec3(-100.0f, 90.0f, 0.0f);

		m_cameraAngleX = -0.4f;
		m_cameraAngleY = -0.0005f;

		m_speed = 0.1f;
		m_mouseSpeed = 0.005f;

		//Projection matrix will be set in separate function as you cant pass bool parameters into the initialise function

		m_viewMatrix = glm::lookAt(m_cameraPos, initTarget, m_up);
	}

	void Camera::setProj(bool _isOrtho)
	{
		//Cant pass this bool into the initialise so for now, a separate function will sort the projection matrix
		if (_isOrtho)
		{
			m_projectionMatrix = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, 0.0f, 1.0f);
		}
		else
		{
			m_projectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		}
	}

	void Camera::onTick()
	{
		//These 2 lines enable the camera to be moved with the mouse input
		//m_cameraAngleY -= getMouse().x * m_mouseSpeed;
		//m_cameraAngleX -= getMouse().y * m_mouseSpeed;

		glm::mat4 m_direction(1.0f);
		m_direction = glm::rotate(m_direction, m_cameraAngleY, glm::vec3(0, 1, 0));
		m_direction = glm::rotate(m_direction, m_cameraAngleX, glm::vec3(1, 0, 0));

		//Camera transform updated with parent entity's transform
		m_cameraPos = m_entity.lock()->getTransform()->Position;
		//Camera moved slightly up so youre not seeing inside the model
		m_cameraPos += glm::vec3(0, 1, 0);

		m_viewMatrix = glm::mat4(1);
		m_viewMatrix = glm::translate(m_viewMatrix, m_cameraPos);
		m_viewMatrix = glm::rotate(m_viewMatrix, m_cameraAngleY, glm::vec3(0, 1, 0));
		m_viewMatrix = glm::rotate(m_viewMatrix, m_cameraAngleX, glm::vec3(1, 0, 0));
		m_viewMatrix = glm::inverse(m_viewMatrix);
	}
	
	glm::vec2 Camera::getMouse()
	{
		return getMouseInput()->m_mouseMove;
	}

}