#include <GEPEngine/Texture.h>

namespace GEPEngine
{
	void Texture::onLoad()
	{
		m_texture = std::make_shared<Graphics::Texture>(getPath());
	}
}