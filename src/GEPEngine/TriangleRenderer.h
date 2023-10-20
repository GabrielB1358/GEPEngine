//include component
#pragma once
#include <Graphics/Rend.h>
#include "Component.h"

namespace GEPEngine
{

	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		~TriangleRenderer();

		void onInitialise();

		std::shared_ptr<Vao> vao;



		std::shared_ptr<Shader> myShader;
		std::shared_ptr<Texture> mytex;


	private:
		void onDisplay() override;
	};
}