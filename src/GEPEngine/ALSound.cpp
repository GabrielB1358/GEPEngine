#include "ALSound.h"

ALSound::ALSound()
{
}

ALSound::ALSound(glm::vec3 _listenerPos)
{
	aDevice = alcOpenDevice(NULL);

	if (!aDevice)
	{
		throw std::runtime_error("Couldn't open audio device");
	}

	aContext = alcCreateContext(aDevice, NULL);

	if (!aContext)
	{
		alcCloseDevice(aDevice);
		throw std::runtime_error("Couldn't create audio context");
	}

	if (!alcMakeContextCurrent(aContext))
	{
		alcDestroyContext(aContext);
		alcCloseDevice(aDevice);
		throw std::runtime_error("Couldn't make context current");
	}


	alListener3f(AL_POSITION, _listenerPos.x, _listenerPos.y, _listenerPos.z);

	//	PREPARE BUFFER
	ALenum format = 0;
	ALsizei freq = 0;

	std::vector<unsigned char> bufferData;
}

void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&)
{
	int channels = 0;
	int sampleRate = 0;
	short* ouput = NULL;
}