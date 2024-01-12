#include <GEPEngine/Texture.h>

namespace GEPEngine
{
	void Texture::onLoad()
	{
		//this game engine texture class acts as a middle man that creates a Graphics library texture
		m_texture = std::make_shared<Graphics::Texture>(getPath());
	}
	std::shared_ptr<Graphics::Texture> Texture::getTexture()
	{
		return m_texture;
	}
}