#include "Light.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

namespace GEPEngine
{
	void Light::onTick()
	{
		getCore()->setLightPos(getEntity()->getTransform()->Position);
	}
}