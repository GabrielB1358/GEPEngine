#include "ALListener.h"
#include "Entity.h"

namespace GEPEngine
{

	void ALListener::initialise()
	{
		Pos = glm::vec3(0);
		
	}

	void ALListener::onTick()
	{
		if (Pos != getEntityPos())
		{
			Pos = getEntityPos();

			alListener3f(AL_POSITION, Pos.x, Pos.y, Pos.z);
		}
	}

	glm::vec3 ALListener::getEntityPos()
	{
		return getEntity()->getTransform()->Position;
	}

}