#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <AL/al.h>
#include <AL/alc.h>
#include "Component.h"
#include "Resource.h"

#include <stdexcept>
#include <vector>

namespace GEPEngine
{
	struct Entity;
	struct Core;

	struct ALSoundSrc : Resource
	{
		ALSoundSrc();

		void onLoad();

		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);

		void playSound();
	
		ALuint sourceId = 0;
		
	};
}
