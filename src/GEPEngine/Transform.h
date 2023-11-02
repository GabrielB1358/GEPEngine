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

		float rotation;

		glm::mat4 getModel(glm::vec3 _rot);

		void Move(glm::vec3 _pos);
	private:

	};
}