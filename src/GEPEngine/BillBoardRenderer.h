#pragma once
#include <Graphics/Rend.h>
#include "Component.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"

namespace GEPEngine
{

	struct BillBoardRenderer : Component
	{
		void onDisplay() override;

		void setVao(std::shared_ptr<Graphics::Vao> _vao);
		void setTexture(std::shared_ptr<Texture> _tex);
		void setShader(std::string _path);
		
	};
}