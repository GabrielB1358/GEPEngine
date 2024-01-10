#pragma once
#include <GEPEngine/Component.h>

namespace GEPEngine
{

	struct Light : Component
	{
		void onTick() override;
	};
}