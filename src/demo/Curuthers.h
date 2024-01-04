#pragma once
#include <GEPEngine/Rigidbody.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/ModelRenderer.h>


struct Curuthers : GEPEngine::Component
{
	void initialise();

	void Move(glm::vec3 _move);

	void Scale(glm::vec3 _scale);

	float angle;

private:
	std::shared_ptr<GEPEngine::ModelRenderer> m_renderer;
	std::shared_ptr<GEPEngine::BoxCollider> m_collider;
	std::shared_ptr<GEPEngine::Rigidbody> m_rigibody;

	void onTick() override;
};