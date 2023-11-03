#include <GEPEngine/Shader.h>

namespace GEPEngine
{
	void Shader::onLoad()
	{
		m_shader = std::make_shared<Graphics::Shader>(getPath() + ".vert", getPath() + ".frag");
	}
}