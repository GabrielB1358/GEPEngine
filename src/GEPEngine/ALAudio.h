#pragma once
#include "Component.h"
#include "ALSoundSrc.h"

namespace GEPEngine
{
	struct ALAudio : Component
	{
		ALAudio();
		~ALAudio();


		void initialise(std::string _path);

		void onTick() override;

		void playSound();

		void playMusic(std::string _path);


		std::shared_ptr<ALSoundSrc> m_source;
		std::string m_path;
		glm::vec3 m_Pos;
	};
}