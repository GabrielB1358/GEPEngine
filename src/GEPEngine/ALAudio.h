#pragma once
#include "ALSoundSrc.h"
#include "Component.h"

namespace GEPEngine
{
	struct ALAudio : Component
	{
		ALAudio();
		~ALAudio();

		void initialise(std::string _path);
		void onTick() override;

		void playSound();
		void playMusic(std::string _path);

		std::shared_ptr<ALSoundSrc> getSource();
		std::string getPath();
		glm::vec3 getSoundPos();

		void setSource(std::shared_ptr<ALSoundSrc> _source);
		void setPath(std::string _string);
		void setSoundPos(glm::vec3 _pos);

	private:
		std::shared_ptr<ALSoundSrc> m_source;
		std::string m_path;
		glm::vec3 m_Pos;
	};
}