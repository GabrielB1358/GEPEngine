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

#include "stb_vorbis.c"

struct ALSound
{
	ALSound(glm::vec3 _listenerPos);
	ALSound();

	void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&);

	ALCdevice* aDevice;
	ALCcontext* aContext;
};