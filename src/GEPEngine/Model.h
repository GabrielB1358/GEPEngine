#pragma once
#include "Resource.h"
#include <Graphics/WavefrontMesh.h>

namespace GEPEngine
{
	struct Model : Resource
	{
		void onLoad();

		std::shared_ptr<Graphics::WavefrontMesh> getModel();

	private:
		std::shared_ptr<Graphics::WavefrontMesh> m_model;
	};
}