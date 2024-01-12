#pragma once
#include <GEPEngine/Component.h>
#include <GEPEngine/BoxCollider.h>
#include <GEPEngine/ModelRenderer.h>

namespace GEPEngine
{

	struct Floor : Component
	{
		void initialise();

		//std::shared_ptr<BoxCollider> m_floorCollider;
		
		std::shared_ptr<ModelRenderer> m_renderer;
	};
}