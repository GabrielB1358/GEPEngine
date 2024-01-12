#pragma once
#include "Resource.h"
#include <Graphics/WavefrontMesh.h>

namespace GEPEngine
{
	struct Model : Resource
	{
		//GEPEngine model resource just creates a Graphics model

		//Inherited onLoad function acts like a constructor
		void onLoad();

		std::shared_ptr<Graphics::WavefrontMesh> getModel();

	private:
		std::shared_ptr<Graphics::WavefrontMesh> m_model;
	};
}