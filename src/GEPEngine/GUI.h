#pragma once
#include <memory>
#include <Graphics/Rend.h>
#include "Shader.h"
#include "Texture.h"

namespace GEPEngine
{
	enum mouseState
	{
		Down,
		Held,
		Up
	};

	struct Core;
	struct GUI
	{
		void initialise(std::shared_ptr<Core> _core);

		void draw(glm::vec2 _pos, glm::vec2 _size, std::string _path);

		bool Button(std::string _downPath, std::string _upPath, glm::vec2 _pos, glm::vec2 _size);

		float mapping(float _inputPixel, float _winStart, float _winEnd, float _rangeStart, float _rangeEnd);

		bool doesMouseOverlap(glm::vec2 _pos, glm::vec2 _size);

	private:
		std::shared_ptr<Core> m_core;
		std::shared_ptr<Graphics::Vao> m_vao;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<Texture> m_texture;
		std::string m_texPath;

		glm::vec2 m_screenSpace;
		glm::vec2 m_screenSize;
		glm::mat4 _modelMatrix;

		bool buttonUp;
		bool buttonDown;
	};
}