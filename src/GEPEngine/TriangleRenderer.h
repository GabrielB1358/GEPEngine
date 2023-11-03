#pragma once
#include <Graphics/Rend.h>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Transform.h"

#include "Component.h"


namespace GEPEngine
{

	struct TriangleRenderer : Component
	{
		TriangleRenderer();

		void onInitialise();


		std::shared_ptr<Graphics::Vao> vao;
		std::shared_ptr<Graphics::Shader> myShader;
		std::shared_ptr<Graphics::Texture> mytex;


		float angle;

		//Model Loader stuff
		std::shared_ptr<GEPEngine::Shader> m_Shader;
		std::shared_ptr<GEPEngine::Texture> m_Texture;
		std::shared_ptr<GEPEngine::Model> m_Model;

		void setFragPath(std::string _path);
		std::string getFragPath();

		void setVertPath(std::string _path);
		std::string getVertPath();

		void setModel(std::shared_ptr<GEPEngine::Model> _model);
		void setTexture(std::shared_ptr<GEPEngine::Texture> _texture);

		void assembleShader();
		void Render();


	private:
		void onDisplay() override;
		void onTick() override;

		//model loader stuff
		std::string m_fragPath;
		std::string m_vertPath;
	};
}