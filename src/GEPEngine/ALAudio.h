#include "Resource.h"
#include <string>
#include <memory>
#include <vector>

namespace GEPEngine
{
	struct ALAudio : Resource
	{
		friend struct ALSoundSrc;
		
		static ALCdevice* aDevice;
		static ALCcontext* aContext;

	private:

		//Audio sources has to be a vec of ALuints as theyre what determines the source
		std::vector<ALuint> m_audioSources;
	};
}