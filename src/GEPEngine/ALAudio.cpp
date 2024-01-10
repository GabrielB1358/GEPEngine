#include <GEPEngine/ALAudio.h>
#include "Core.h"
#include "Transform.h"

namespace GEPEngine
{
	ALAudio::~ALAudio()
	{
	}
	ALAudio::ALAudio()
	{
	}


	void ALAudio::initialise(std::string _path)
	{
		m_path = _path;
		m_source = getCore()->getResources()->load<ALSoundSrc>(_path);
	}

	void ALAudio::onTick()
	{
		m_Pos = getEntity()->getTransform()->Position;
		alSource3f(m_source->returnSourceId(), AL_POSITION, m_Pos.x, m_Pos.y, m_Pos.z);
	}

	void ALAudio::playSound()
	{
		m_source = getCore()->getResources()->load<ALSoundSrc>(m_path);
		m_source->playSound();
	}

	void ALAudio::playMusic(std::string _path)
	{
		std::shared_ptr<ALSoundSrc> rtn = getCore()->getResources()->load<ALSoundSrc>(_path);

		rtn->playSound();
	}

}