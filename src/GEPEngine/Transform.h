#pragma once
#include "Component.h"

namespace GEPEngine
{

	struct Transform : Component
	{
		Transform();

		glm::vec3 Position;
		glm::vec3 Scale;
		glm::vec3 Rotation;
		glm::mat4 rotMat;

		glm::mat4 modelMatrix;
		float rotation;

		glm::mat4 getRotMat();
		glm::vec3 getPos();
		glm::vec3 getScale();

		void setRot(glm::vec3 _rot);
		void setPos(glm::vec3 _pos);
		void setScale(glm::vec3 _scale);

		void Rotate(glm::vec3 _rot, float angle);
	};
}