#include "ALListener.h"
#include "Entity.h"

namespace GEPEngine
{

	void ALListener::initialise()
	{
		oldPos = glm::vec3(0);
	}

	void ALListener::onTick()
	{
		newPos = getEntityPos();
		if (oldPos != newPos)
		{
			oldPos = newPos;
			alListener3f(AL_POSITION, newPos.x, newPos.y, newPos.z);
		}
	}

	glm::vec3 ALListener::getEntityPos()
	{
		return getEntity()->getTransform()->Position;
	}

}