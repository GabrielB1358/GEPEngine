#pragma once

#include "Resource.h"
#include <Graphics/Shader.h>

namespace GEPEngine
{
	struct Shader : Resource
	{
		//GEPEngine shader just creates a Graphics library shader

		//onload function acts as a constructor
		void onLoad() override;

		std::shared_ptr<Graphics::Shader> getShader();

	private:
		std::shared_ptr<Graphics::Shader> m_shader;
	};
}