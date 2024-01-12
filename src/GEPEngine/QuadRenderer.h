#pragma once
#include <Graphics/Rend.h>
#include "Component.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"

namespace GEPEngine
{

	struct QuadRenderer : Component
	{
		//Quad renderer component is used to render 2D images in the 3D world like a billboard
		void onDisplay() override;

		void setTexture(std::string _p);
		void setShader(std::string _p);
		void setVao(std::shared_ptr<Graphics::Vao> _vao);

	private:
		//Shader, texture, camera
		std::shared_ptr<Texture> m_tex;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<Camera> m_camera;

		std::string m_texPath;
		std::string m_shadPath;
		std::shared_ptr<Graphics::Vao> m_vao;
		
	};
}