#pragma once
#include <GEPEngine/Rigidbody.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/ModelRenderer.h>
#include <GEPEngine/ALAudio.h>

struct Curuthers : GEPEngine::Component
{
	Curuthers();
	Curuthers(bool greg);

	void initialise();

	void Move(float _x, float _y, float _z);

	void Scale(float _x, float _y, float _z);

	void onTick() override;
	void onGUI() override;
	void onKill() override;

private:
	float m_angle;

	std::shared_ptr<GEPEngine::ModelRenderer> m_renderer;
	std::shared_ptr<GEPEngine::BoxCollider> m_collider;
	std::shared_ptr<GEPEngine::Rigidbody> m_rigibody;

	std::shared_ptr<GEPEngine::ALAudio> m_hornSound;
	std::shared_ptr<GEPEngine::ALAudio> m_pigeonSound;
};