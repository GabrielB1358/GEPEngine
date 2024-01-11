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
		m_newPos = getEntityPos();
		if (m_oldPos != m_newPos)
		{
			m_oldPos = m_newPos;
			alListener3f(AL_POSITION, m_newPos.x, m_newPos.y, m_newPos.z);
		}
	}

	glm::vec3 ALListener::getEntityPos()
	{
		return getEntity()->getTransform()->getPosition();
	}

}