#pragma once
#include "Component.h"
#include "ALSoundSrc.h"

namespace GEPEngine
{
	struct ALAudio : Component
	{
		ALAudio();
		~ALAudio();

		void onTick() override;

		void playSound(std::string _path);
	

	};
}