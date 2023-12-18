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

#include "Component.h"

namespace GEPEngine
{
	struct ALSound : Component
	{
		ALSound(std::string _path, glm::vec3 _sourcePos);
		ALSound();

		void initialise() override;
		void onTick();
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);
		void addNewSource(std::string _path, glm::vec3 _pos);
		void setupSource(std::string _path, glm::vec3 _pos);

		std::vector<ALuint> audioSources;

		ALCdevice* aDevice;
		ALCcontext* aContext;
		ALuint sourceId = 0;
		std::string m_path;
		
	};
}
