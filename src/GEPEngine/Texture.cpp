#include <GEPEngine/Texture.h>

namespace GEPEngine
{
	void Texture::onLoad()
	{
		m_texture = std::make_shared<Graphics::Texture>(getPath());
	}
	std::shared_ptr<Graphics::Texture> Texture::getTexture()
	{
		return m_texture;
	}
}