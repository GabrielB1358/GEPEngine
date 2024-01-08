#include "Light.h"
#include "Entity.h"
#include "Transform.h"

namespace GEPEngine
{
	glm::vec3 Light::getPosition()
	{
		return getEntity()->getTransform()->Position;
	}
}