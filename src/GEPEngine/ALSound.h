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
//#include "stb_vorbis.c"

namespace GEPEngine
{
	struct ALSound : Component
	{
		//ALSound(glm::vec3 _listenerPos);
		//ALSound();

		void initialise() override;
		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);

		ALCdevice* aDevice;
		ALCcontext* aContext;
	};
}
