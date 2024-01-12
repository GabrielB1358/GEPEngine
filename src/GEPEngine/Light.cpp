#include "Light.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

namespace GEPEngine
{
	//one function returns light position from the entity the light is attached to's position
	glm::vec3 Light::getPos()
	{
		return getEntity()->getTransform()->getPosition();
	}
}