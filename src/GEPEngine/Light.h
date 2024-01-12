#pragma once
#include <GEPEngine/Component.h>

namespace GEPEngine
{

	struct Light : Component
	{
		//Light component controls the point light position which is then passed to the shader
		glm::vec3 getPos();
	};
}