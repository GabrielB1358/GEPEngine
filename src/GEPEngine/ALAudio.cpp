#include <GEPEngine/ALAudio.h>
#include "Core.h"

namespace GEPEngine
{
	ALAudio::ALAudio()
	{
			
	}

	ALAudio::~ALAudio()
	{
	}

	void ALAudio::onTick()
	{

	}

	void ALAudio::playSound(std::string _path)
	{
		std::shared_ptr<ALSoundSrc> rtn;
		rtn = getCore()->getResources()->load<ALSoundSrc>(_path);

		rtn->playSound();
	}

}