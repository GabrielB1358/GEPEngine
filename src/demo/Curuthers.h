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

	void initialise();
	void onTick() override;
	void onGUI() override;
	void onKill() override;

	void Move(float _x, float _y, float _z);
	void Scale(float _x, float _y, float _z);

private:

	std::shared_ptr<GEPEngine::ModelRenderer> m_renderer;

	std::shared_ptr<GEPEngine::ALAudio> m_hornSound;
	std::shared_ptr<GEPEngine::ALAudio> m_pigeonSound;
};