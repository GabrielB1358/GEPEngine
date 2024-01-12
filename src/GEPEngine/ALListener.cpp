#include "ALListener.h"
#include "Entity.h"

namespace GEPEngine
{

	void ALListener::initialise()
	{
		m_oldPos = glm::vec3(0);
	}

	void ALListener::onTick()
	{
		//Checks if the position has changed since last frame, this avoids calling the listener command every tick which is demanding
		m_newPos = getEntityPos();
		if (m_oldPos != m_newPos)
		{
			m_oldPos = m_newPos;
			//Updates listener position for directional audio
			alListener3f(AL_POSITION, m_newPos.x, m_newPos.y, m_newPos.z);
		}
	}

	glm::vec3 ALListener::getEntityPos()
	{
		return getEntity()->getPosition();
	}

}