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


		glm::mat4 getModel();

		void Move(glm::vec3 _pos);
		void Rotate(glm::vec3 _rot);

		int angle;
	private:

	};
}