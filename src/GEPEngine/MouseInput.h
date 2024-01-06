#pragma once
#include <GEPEngine/Keyboard.h>

namespace GEPEngine
{

	struct MouseInput
	{
		MouseInput();

		void processMouseInput(SDL_Event _e);
		void postMouseProcess();

		inline glm::vec2 getMouseMove() { return m_mouseMove; }

		inline glm::vec2 getMouseCoords() { return m_mouseCoords; }

		glm::vec2 m_mouseMove{ 0 };
		glm::vec2 m_mouseCoords;	
	};
}