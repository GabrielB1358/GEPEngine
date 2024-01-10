#include "Light.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

namespace GEPEngine
{
	glm::vec3 Light::getPos()
	{
		return getEntity()->getTransform()->Position;
	}
}