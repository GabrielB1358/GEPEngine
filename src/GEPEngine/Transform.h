#pragma once
#include "Component.h"

namespace GEPEngine
{

	struct Transform : Component
	{
		//Transform component holds variables pertaining to the entitys movement
		Transform();

		void Move(glm::vec3 _pos);
		void Rotate(glm::vec3 _rot);

		glm::mat4 getModel();
		glm::vec3 getPosition();
		glm::vec3 getScale();
		glm::vec3 getRotation();
		glm::vec3 getLastTickPos();
		int getAngle();

		void setPosition(glm::vec3 _pos);
		void setLastTickPos(glm::vec3 _pos);
		void setScale(glm::vec3 _scale);
		void setRotation(glm::vec3 _rot);
		void setAngle(int angle);
		void endFrame();

	private:
		glm::vec3 m_position;
		glm::vec3 m_scale;
		glm::vec3 m_rotation;
		glm::vec3 m_lastTickPosition;

		int m_angle;
	};
}