#pragma once
#include "Resource.h"
#include <string>
#include <memory>
#include <vector>

namespace GEPEngine
{
	struct ALAudio : Resource
	{
		friend struct ALSoundSrc;
		
		ALCdevice* aDevice;
		ALCcontext* aContext;

	private:

		//Audio sources has to be a vec of ALuints as theyre what determines the source
		std::vector<ALuint> m_audioSources;
	};
}