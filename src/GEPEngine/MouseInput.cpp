#include "MouseInput.h"

namespace GEPEngine
{


	void MouseInput::processMouseInput(SDL_Event _e, glm::ivec2 _wSize)
	{
		if (_e.type == SDL_MOUSEMOTION)
		{
			m_mouseCoords.x = _e.motion.x;
			m_mouseCoords.y = _e.motion.y;

			//Hard coded for 720p, would have to change for different resolutions
			m_mouseMove.x += m_mouseCoords.x - (_wSize.x / 2);
			m_mouseMove.y += m_mouseCoords.y - (_wSize.y / 2);

			//SDL_WarpMouseInWindow(NULL, (_wSize.x / 2), (_wSize.y / 2));
		}
		else if (_e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (_e.button.button == SDL_BUTTON_LEFT)
				lMouse = true;
			if (_e.button.button == SDL_BUTTON_RIGHT)
				rMouse = true;
			if (_e.button.button == SDL_BUTTON_MIDDLE)
				mMouse = true;
		}
		else if (_e.type == SDL_MOUSEBUTTONUP)
		{
			if (_e.button.button == SDL_BUTTON_LEFT)
				lMouse = false;
			if (_e.button.button == SDL_BUTTON_RIGHT)
				rMouse = false;
			if (_e.button.button == SDL_BUTTON_MIDDLE)
				mMouse = false;
		}

	}

	void MouseInput::postMouseProcess()
	{
		m_mouseMove = glm::vec2(0);
	}

}