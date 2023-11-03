#pragma once
#include <Graphics/Rend.h>
#include "Component.h"
#include "Resource.h"


namespace GEPEngine
{

	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		~TriangleRenderer();

		void onInitialise();

		std::shared_ptr<Graphics::Vao> vao;



		std::shared_ptr<Graphics::Shader> myShader;
		std::shared_ptr<Graphics::Texture> mytex;


		float angle;

	private:
		void onDisplay() override;
		void onTick() override;
	};
}