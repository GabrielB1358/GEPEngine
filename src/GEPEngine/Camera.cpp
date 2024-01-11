#include "Camera.h"
#include <GEPEngine/Input.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Core.h"

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

		m_perspProjmat = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		m_orthoProjmat = glm::ortho(0.0f, (float)getCore()->getWinSize().x, (float)getCore()->getWinSize().y, 0.0f, 0.0f, 1.0f);
	}


	void Camera::onTick()
	{
		//These 2 lines enable the camera to be moved with the mouse input
		// do the warpmouseinwindow for this ^^
		//m_cameraAngleY -= getMouse().x * m_mouseSpeed;
		//m_cameraAngleX -= getMouse().y * m_mouseSpeed;

		glm::mat4 m_direction(1.0f);
		m_direction = glm::rotate(m_direction, m_cameraAngleY, glm::vec3(0, 1, 0));
		m_direction = glm::rotate(m_direction, m_cameraAngleX, glm::vec3(1, 0, 0));

		//Camera transform updated with parent entity's transform
		m_cameraPos = getEntity()->getTransform()->getPosition();
		//Camera moved slightly up so youre not seeing inside the model
		m_cameraPos += glm::vec3(0, 1, 0);

		m_viewMatrix = glm::mat4(1);
		m_viewMatrix = glm::translate(m_viewMatrix, m_cameraPos);
		m_viewMatrix = glm::rotate(m_viewMatrix, m_cameraAngleY, glm::vec3(0, 1, 0));
		m_viewMatrix = glm::rotate(m_viewMatrix, m_cameraAngleX, glm::vec3(1, 0, 0));
		m_viewMatrix = glm::inverse(m_viewMatrix);
	}
	
	glm::mat4 Camera::getViewMat()
	{
		return m_viewMatrix;
	}

	glm::mat4 Camera::getOrthoProjMat()
	{
		return m_orthoProjmat;
	}

	glm::mat4 Camera::getPerspProjMat()
	{
		return m_perspProjmat;
	}

	glm::vec2 Camera::getMouse()
	{
		return getInput()->getMouseMove();
	}

	void Camera::setViewMat(glm::mat4 _view)
	{
		m_viewMatrix = _view;
	}

	void Camera::setOrthoProjMat(glm::mat4 _ortho)
	{
		m_orthoProjmat = _ortho;
	}

	void Camera::setPerspProjMat(glm::mat4 _persp)
	{
		m_perspProjmat = _persp;
	}

	void Camera::setPos(glm::vec3 _pos)
	{
		m_cameraPos = _pos;
	}
}