#pragma once
#include <memory>
#include "Core.h"

namespace GEPEngine
{
	struct GUI
	{
		void onGUI();

	

		std::weak_ptr<Core> m_core;
	};
}