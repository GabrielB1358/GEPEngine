#pragma once
#include <Graphics/Rend.h>
#include "Component.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"


namespace GEPEngine
{

	struct ModelRenderer : Component
	{
		//Modelrenderer component stores and controls variables allowing for rendering a 3D model into the world

		ModelRenderer();
		void onInitialise();
		void onDisplay() override;
		void onTick() override;

		void setFragPath(std::string _path);
		void setVertPath(std::string _path);
		
		std::string getVertPath();
		std::string getFragPath();

		void setModel(std::string _p);
		void setTexture(std::string _p);
		void setShader(std::string _p);

	private:
		std::shared_ptr<Camera> m_Camera;

		std::shared_ptr<GEPEngine::Shader> m_Shader;
		std::shared_ptr<GEPEngine::Texture> m_Texture;
		std::shared_ptr<GEPEngine::Model> m_Model;

		std::string m_fragPath;
		std::string m_vertPath;
		std::string m_modPath;
		std::string m_texPath;
		std::string m_shaderPath;
	};
}