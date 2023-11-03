#include "Resource.h"
#include <Graphics/WavefrontMesh.h>

namespace GEPEngine
{
	struct Model : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<Graphics::WavefrontMesh> m_model;
	};
}