#pragma once
#include "Resource.h"
#include <Graphics/Texture.h>

namespace GEPEngine
{
	struct Texture : Resource
	{
		//GEPEngine texture creates a Graphics shader

		//onload acts as a constructor
		void onLoad();

		std::shared_ptr<Graphics::Texture> getTexture();

	private:
		std::shared_ptr<Graphics::Texture> m_texture;
	};
}