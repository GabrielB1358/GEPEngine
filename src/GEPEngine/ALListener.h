#pragma once
#include "Component.h"
#include "ALAudio.h"

namespace GEPEngine
{

	struct ALListener : Component
	{
		void initialise() override;

		void onTick() override;

		glm::vec3 getPos();

		glm::vec3 oldPos;
		glm::vec3 newPos;
	};
}