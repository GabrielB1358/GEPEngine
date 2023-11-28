#pragma once
#include <GEPEngine/Core.h>
#include <GEPEngine/Component.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/ModelRenderer.h>

struct evilBloke : GEPEngine::Component
{
	void initialise();

	void Move(glm::vec3 _move);
	float angle;

private:
	std::shared_ptr<GEPEngine::ModelRenderer> m_renderer;
	std::shared_ptr<GEPEngine::BoxCollider> m_collider;

	void onTick() override;
};