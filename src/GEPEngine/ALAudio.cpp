#include <GEPEngine/ALAudio.h>
#include "Core.h"

namespace GEPEngine
{
	ALAudio::ALAudio()
	{
		soundPath = "";
	}

	ALAudio::~ALAudio()
	{
	}

	void ALAudio::setSound(std::string _path)
	{
		m_source = getCore()->getResources()->load<ALSoundSrc>(_path);

	}

	void ALAudio::playSound()
	{
		m_source->playSound();
	}

}