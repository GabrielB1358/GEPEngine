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

	std::shared_ptr<ALSoundSrc> ALAudio::addSource(std::string _path)
	{
		std::shared_ptr<ALSoundSrc> rtn;
		rtn = getCore()->getResources()->load<ALSoundSrc>(_path);

		m_sources.push_back(rtn);

		return rtn;
	}

}