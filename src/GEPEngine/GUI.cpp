#include "GUI.h"
#include "Core.h"
#include "Transform.h"

namespace GEPEngine
{
	void GUI::initialise(std::shared_ptr<Core> _core)
	{
		m_core = _core;

		std::shared_ptr<Graphics::Vbo> m_positions = std::make_shared<Graphics::Vbo>();
		std::shared_ptr<Graphics::Vbo> m_texCoords = std::make_shared<Graphics::Vbo>();

		m_vao = std::make_shared<Graphics::Vao>();
		
		m_positions->Add(glm::vec3(-0.5f, 0.5f, 0.0f));
		m_positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		m_positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		m_positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		m_positions->Add(glm::vec3(0.5f, 0.5f, 0.0f));
		m_positions->Add(glm::vec3(-0.5f, 0.5f, 0.0f));

		m_texCoords->Add(glm::vec2(0.0f, 1.0f));
		m_texCoords->Add(glm::vec2(0.0f, 0.0f));
		m_texCoords->Add(glm::vec2(1.0f, 0.0f));
		m_texCoords->Add(glm::vec2(1.0f, 0.0f));
		m_texCoords->Add(glm::vec2(1.0f, 1.0f));
		m_texCoords->Add(glm::vec2(0.0f, 1.0f));

		m_vao->AddVbo(m_positions);
		m_vao->AddVbo(m_texCoords);
	}

	void GUI::draw(glm::vec2 _pos, glm::vec2 _size, std::string _path)
	{
		m_screenSize = m_core->getWinSize();
		m_screenSpace.x = (mapping(_pos.x, 0, m_screenSize.x, 0, 1) * m_screenSize.x);
		m_screenSpace.y = (mapping(_pos.y, 0, m_screenSize.y, 0, 1) * m_screenSize.y);

		m_modelMatrix = glm::scale(glm::translate(glm::mat4(1), glm::vec3(m_screenSpace, 0.0f)), glm::vec3(_size, 1.0f));

		m_texture = m_core->getResources()->load<Texture>(_path);
		m_shader = m_core->getResources()->load<Shader>("../Shaders/GUI");
		m_shader->getShader()->RenderQuad(m_vao, m_texture->getTexture(), m_modelMatrix, m_core->getCamera());
	}

	bool GUI::Button(std::string _downPath, std::string _upPath, glm::vec2 _pos, glm::vec2 _size)
	{
		if (doesMouseOverlap(_pos, _size))
		{
			if (m_core->getInput()->isKey(Keys::leftM))
			{
				draw(_pos, _size, _downPath);
				return true;
			}
			else
			{
				draw(_pos, _size, _upPath);
				return false;
			}
		}
		else
		{
			draw(_pos, _size, _upPath);
			return false;
		}
	}

	bool GUI::doesMouseOverlap(glm::vec2 _pos, glm::vec2 _size)
	{
		glm::vec2 msTmp = m_core->getInput()->getMouseCoords();
		_size = _size / 2.0f;
		if (msTmp.x < (_pos.x - _size.x))
			return false;
		if (msTmp.x > (_pos.x + _size.x))
			return false;
		if (msTmp.y < (_pos.y - _size.y))
			return false;
		if (msTmp.y > (_pos.y + _size.y))
			return false;

		return true;
	}

	float GUI::mapping(float _inputPixel, float _winStart, float _winEnd, float _rangeStart, float _rangeEnd)
	{
		return (_inputPixel - _winStart) * ((_rangeEnd - _rangeStart) / (_winEnd - _winStart)) + _rangeStart;
	}
}