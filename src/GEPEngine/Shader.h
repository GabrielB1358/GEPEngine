#pragma once

#include "Resource.h"
#include <Graphics/Shader.h>

namespace GEPEngine
{
	struct Shader : Resource
	{
		void onLoad() override;

	private:
		std::shared_ptr<Graphics::Shader> m_shader;
	};
}