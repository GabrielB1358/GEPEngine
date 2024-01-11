#pragma once
#include "Component.h"

namespace GEPEngine
{

	struct Transform : Component
	{
		Transform();

		void Move(glm::vec3 _pos);
		void Rotate(glm::vec3 _rot);

		glm::mat4 getModel();
		glm::vec3 getPosition();
		glm::vec3 getScale();
		glm::vec3 getRotation();
		int getAngle();

		void setPosition(glm::vec3 _pos);
		void setScale(glm::vec3 _scale);
		void setRotation(glm::vec3 _rot);
		void setAngle(int angle);

	private:
		glm::vec3 m_position;
		glm::vec3 m_scale;
		glm::vec3 m_rotation;

		int m_angle;
	};
}