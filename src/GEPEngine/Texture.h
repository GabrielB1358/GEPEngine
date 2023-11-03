#pragma once
#include "Resource.h"
#include <Graphics/Texture.h>

namespace GEPEngine
{
	struct Texture : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<Graphics::Texture> m_texture;
	};
}