#pragma once
#include <AL/al.h>
#include <AL/alc.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdexcept>
#include <vector>
#include <string>
#include <memory>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "ALAudio.h"

#include "Component.h"

namespace GEPEngine
{
	struct Entity;
	struct Core;

	struct ALSoundSrc : Component
	{
		ALSoundSrc();

		void initialise() override;
		void onTick();
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);

		void setAudio(ALAudio _audio); //need to have Audio as parameter? using core->resources->load-> return audio
		void setLoop(bool _doesLoop);
		void playSound(std::string _path);
	

		ALCdevice* aDevice;
		ALCcontext* aContext;
		ALuint sourceId = 0;
		std::string m_path;
		
	};
}
