#include "MouseInput.h"

namespace GEPEngine
{
	MouseInput::MouseInput()
	{
		//m_mouseMove = glm::vec2(0);
	}

	void MouseInput::processMouseInput(SDL_Event _e)
	{
		if (_e.type == SDL_MOUSEMOTION)
		{
			m_mouseCoords.x = _e.motion.x;
			m_mouseCoords.y = _e.motion.y;

			//Hard coded for 720p, would have to change for different resolutions
			m_mouseMove.x += m_mouseCoords.x - (1280 / 2);
			m_mouseMove.y += m_mouseCoords.y - 360;
			SDL_WarpMouseInWindow(NULL, 640, 360);
		}
	}

	void MouseInput::postMouseProcess()
	{
		m_mouseMove = glm::vec2(0);

		//SDL_WarpMouseInWindow(NULL, 640, 360);
	}

}