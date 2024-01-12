#pragma once
#include <GEPEngine/Rigidbody.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/ALAudio.h>

namespace GEPEngine
{
	struct ModelRenderer;
	struct Player : Component
	{
		Player();

		void initialise();
		void onTick() override;
		void onGUI() override;
		void onKill() override;

		void Move(float _x, float _y, float _z);
		void Scale(float _x, float _y, float _z);


		float m_speed;

		std::shared_ptr<ModelRenderer> m_renderer;

		std::shared_ptr<ALAudio> m_hornSound;
		std::shared_ptr<ALAudio> m_pigeonSound;
	};
}
