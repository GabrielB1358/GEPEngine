#pragma once
#include <GEPEngine/Component.h>

namespace GEPEngine
{

	struct Light : Component
	{
		glm::vec3 getPos();
	};
}