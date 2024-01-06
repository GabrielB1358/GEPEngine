#pragma once
#include "Component.h"
#include "ALSoundSrc.h"

namespace GEPEngine
{
	struct ALAudio : Component
	{
		ALAudio();
		~ALAudio();

		void setSound(std::string _path);

		void playSound();

		std::shared_ptr<ALSoundSrc> getSource() { return m_source; }
	
	private:
		std::shared_ptr<ALSoundSrc> m_source;
		std::string soundPath;

	};
}