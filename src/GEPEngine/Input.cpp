#include "Input.h"

namespace GEPEngine
{
	Input::Input()
	{
	}

	void Input::processKeys(SDL_Event _e, glm::ivec2 _wSize)
	{
		//Keyboard input processing
		if (_e.type == SDL_KEYDOWN)
		{
			if (std::find(keyCodes.begin(), keyCodes.end(), _e.key.keysym.sym) == keyCodes.end())
			{
				keyCodes.push_back(_e.key.keysym.sym);
				pressedKeys.push_back(_e.key.keysym.sym);
			}
		}
		else if (_e.type == SDL_KEYUP)
		{
			for (int i = 0; i < keyCodes.size(); i++)
			{
				if (keyCodes[i] == _e.key.keysym.sym)
				{
					keyCodes.erase(keyCodes.begin() + i);
					releasedKeys.push_back(_e.key.keysym.sym);
				}
			}
		}

		//Mouse input controlling
		if (_e.type == SDL_MOUSEMOTION)
		{
			m_mouseCoords.x = _e.motion.x;
			m_mouseCoords.y = _e.motion.y;


			m_mouseMove.x += m_mouseCoords.x - (_wSize.x / 2);
			m_mouseMove.y += m_mouseCoords.y - (_wSize.y / 2);

			//This line is for if you have the camera controlled by mouse enabled
			//SDL_WarpMouseInWindow(NULL, (_wSize.x / 2), (_wSize.y / 2));
		}
		if (_e.type == SDL_MOUSEBUTTONDOWN)
		{
			for (int i = 0; i < keyCodes.size(); i++)
			{
				if (std::find(keyCodes.begin(), keyCodes.end(), _e.button.button) == keyCodes.end())
				{
					keyCodes.push_back(_e.button.button);
					pressedKeys.push_back(_e.button.button);
				}
			}
		}
		else if (_e.type == SDL_MOUSEBUTTONUP)
		{
			for (int i = 0; i < keyCodes.size(); i++)
			{
				if (keyCodes[i] == _e.button.button)
				{
					keyCodes.erase(keyCodes.begin() + i);
					releasedKeys.push_back(_e.button.button);
				}
			}
		}

		//Gamepad input processing
		//button, joystick
		if (_e.type == SDL_JOYAXISMOTION)
		{
			if (_e.jaxis.which == 0)
			{
				if (_e.jaxis.axis == 0)
					gpMoveJoystick.x = _e.jaxis.value;
				if (_e.jaxis.axis == 1)
					gpMoveJoystick.y = _e.jaxis.value;
			}
			if (_e.jaxis.which == 1)
			{
				if (_e.jaxis.axis == 0)
					gpCamJoystick.x = _e.jaxis.value;
				if (_e.jaxis.axis == 1)
					gpCamJoystick.y = _e.jaxis.value;
			}
		}
		if (_e.type == SDL_CONTROLLERBUTTONDOWN || _e.type == SDL_JOYBUTTONDOWN)
		{
			for (int i = 0; i < keyCodes.size(); i++)
			{
				if (std::find(keyCodes.begin(), keyCodes.end(), _e.button.button) == keyCodes.end())
				{
					keyCodes.push_back(_e.button.button);
					pressedKeys.push_back(_e.button.button);
				}
			}
		}
		else if (_e.type == SDL_CONTROLLERBUTTONUP || _e.type == SDL_JOYBUTTONUP)
		{
			for (int i = 0; i < keyCodes.size(); i++)
			{
				if (keyCodes[i] == _e.button.button)
				{
					keyCodes.erase(keyCodes.begin() + i);
					releasedKeys.push_back(_e.button.button);
				}
			}
		}
	}

	void Input::onTick()
	{
		pressedKeys.clear();
		releasedKeys.clear();

		m_mouseMove = glm::vec2(0);
	}

	bool Input::isKey(Keys keyCode)
	{
		if (std::find(keyCodes.begin(), keyCodes.end(), keyCode) != keyCodes.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Input::isKeyDown(Keys keyCode)
	{
		if (std::find(pressedKeys.begin(), pressedKeys.end(), keyCode) != pressedKeys.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Input::isKeyUp(Keys keyCode)
	{
		if (std::find(releasedKeys.begin(), releasedKeys.end(), keyCode) != releasedKeys.end())
		{
			return true;
		}
		else
			return false;
	}
}