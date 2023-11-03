#include <GEPEngine/Shader.h>

namespace GEPEngine
{
	void Shader::onLoad()
	{
		m_shader = std::make_shared<Graphics::Shader>(getPath() + ".frag", getPath() + ".vert");
	}
	std::shared_ptr<Graphics::Shader> Shader::getShader()
	{
		return m_shader;
	}
}