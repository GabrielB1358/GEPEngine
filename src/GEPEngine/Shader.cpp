#include <GEPEngine/Shader.h>

namespace GEPEngine
{
	void Shader::onLoad()
	{
		//This GameEngine shader class is a middle man that creates a Graphics library shader
		m_shader = std::make_shared<Graphics::Shader>(getPath() + ".frag", getPath() + ".vert");
	}
	std::shared_ptr<Graphics::Shader> Shader::getShader()
	{
		return m_shader;
	}
}