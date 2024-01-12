#pragma once
#include <GEPEngine/Core.h>
#include <GEPEngine/Component.h>
#include <GEPEngine/ModelRenderer.h>
#include "GameLoop.h"


struct Enemy : GEPEngine::Component
{
	void initialise(std::shared_ptr<GEPEngine::GameLoop> _gl);

	void Move(glm::vec3 _move);

	std::shared_ptr<GEPEngine::GameLoop> m_gameLoop;

private:
	std::shared_ptr<GEPEngine::ModelRenderer> m_renderer;
	std::shared_ptr<GEPEngine::BoxCollider> m_collider;

	void onTick() override;
};