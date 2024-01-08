#pragma once
#include <GEPEngine/Keyboard.h>

namespace GEPEngine
{

	struct MouseInput
	{
		void processMouseInput(SDL_Event _e, glm::ivec2 _wSize);
		void postMouseProcess();

		inline glm::vec2 getMouseMove() { return m_mouseMove; }

		inline glm::vec2 getMouseCoords() { return m_mouseCoords; }

		glm::vec2 m_mouseMove;
		glm::vec2 m_mouseCoords;

		bool lMouse, rMouse, mMouse;

		inline bool getLM() { return lMouse; }
		inline bool getRM() { return rMouse; }
		inline bool getMM() { return mMouse; }
	};
}