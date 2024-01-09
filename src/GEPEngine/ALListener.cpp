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
		if (oldPos != getPos())
		{
			newPos = getPos();
			alListener3f(AL_POSITION, newPos.x, newPos.y, newPos.z);
		}
	}

	glm::vec3 ALListener::getPos()
	{
		return getEntity()->getTransform()->Position;
	}

}