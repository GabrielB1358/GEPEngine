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
		m_Pos = getEntity()->getTransform()->getPosition();
		alSource3f(m_source->getSourceId(), AL_POSITION, m_Pos.x, m_Pos.y, m_Pos.z);
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

	std::shared_ptr<ALSoundSrc> ALAudio::getSource()
	{
		return m_source;
	}

	std::string ALAudio::getPath()
	{
		return m_path;
	}

	glm::vec3 ALAudio::getSoundPos()
	{
		return m_Pos;
	}

	void ALAudio::setSource(std::shared_ptr<ALSoundSrc> _source)
	{
		m_source = _source;
	}

	void ALAudio::setPath(std::string _string)
	{
		m_path = _string;
	}

	void ALAudio::setSoundPos(glm::vec3 _pos)
	{
		m_Pos = _pos;
	}

}