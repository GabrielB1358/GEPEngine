#pragma once
#include "Component.h"
#include "ALAudio.h"

namespace GEPEngine
{

	struct ALListener : Component
	{
		//Listener component is used to update the listener position for sound to achieve directional audio

		void initialise() override;
		void onTick() override;

		glm::vec3 getEntityPos();

	private:
		glm::vec3 m_newPos;
		glm::vec3 m_oldPos;
	};
}