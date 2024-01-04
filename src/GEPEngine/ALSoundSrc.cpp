#include <iostream>
#include "ALSoundSrc.h"
#include "Transform.h"
#include "Entity.h"
#include "stb_vorbis.c"

#include <GEPEngine/Core.h>
#include <GEPEngine/Entity.h>

namespace GEPEngine
{
	ALSoundSrc::ALSoundSrc()
	{

	}

	void ALSoundSrc::onTick()
	{
		//Probably wrong tbh youre shit at code

		//This tracks the audio source position to the entity its attached to's position
		//glm::vec3 tmp = getEntity()->getTransform()->Position;
		//alSource3f(sourceId, AL_POSITION, tmp.x, tmp.y, tmp.z);
	}

	void ALSoundSrc::playSound(std::string _path)
	{
		std::shared_ptr<ALuint> st = getCore()->getResources()->load<ALuint>("shitdickandballs");
		//make or find the audio file thing
		//load this new audio (turn initialise funtion into one that sets up buffer and source for playing sound
		//play it
	}

	void ALSoundSrc::initialise()
	{
		//	PREPARE BUFFER

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<unsigned char> bufferData;
		load_ogg("../dixie_horn.ogg", bufferData, format, freq);

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);

		//prepare sound source

		//reset source id to 0 evertime
		alGenSources(1, &sourceId);

		alSource3f(sourceId, AL_POSITION, 0.0f,0.0f,0.0f);
		//alSourcef(sourceId, AL_PITCH, 10);
		//alSourcef(sourceId, AL_GAIN, vol);
		alSourcei(sourceId, AL_BUFFER, bufferId);

		//play sound source
		alSourcePlay(sourceId);

		alcMakeContextCurrent(NULL);
		alcDestroyContext(aContext);
		alcCloseDevice(aDevice);
	}

	void ALSoundSrc::load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.c_str(),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		_buffer.resize(samples * channels * sizeof(short));
		memcpy(&_buffer.at(0), output, _buffer.size());

		// Record the sample rate required by OpenAL
		_freq = sampleRate;

		// Clean up the read data
		free(output);
	}
	
	
	void ALSoundSrc::setAudio(ALAudio _audio)
	{
		
	}

}
