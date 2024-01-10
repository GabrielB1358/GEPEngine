#include "Input.h"

namespace GEPEngine
{
	Input::Input()
	{
		lMouse = false;
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
			if (std::find(keyCodes.begin(), keyCodes.end(), _e.button.button) == keyCodes.end())
			{
				keyCodes.push_back(_e.button.button);
				pressedKeys.push_back(_e.button.button);
			}
			lMouse = true;
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
			lMouse = false;
		}

		//Gamepad input processing
		//button, joystick
		if (_e.type == SDL_JOYAXISMOTION)
		{
			if (_e.jaxis.which == 0)
			{
				if (_e.jaxis.axis == 0)
					gpLeftJoystick.x = _e.jaxis.value;
				if (_e.jaxis.axis == 1)
					gpLeftJoystick.y = _e.jaxis.value;
			}
			if (_e.jaxis.which == 1)
			{
				if (_e.jaxis.axis == 0)
					gpRightJoystick.x = _e.jaxis.value;
				if (_e.jaxis.axis == 1)
					gpRightJoystick.y = _e.jaxis.value;
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

	glm::vec2 Input::getLeftJStick()
	{
		return gpLeftJoystick;
	}

	glm::vec2 Input::getRightJStick()
	{
		return gpRightJoystick;
	}

	void Input::onTick()
	{
		for (int i = 0; i < keyCodes.size(); i++)
		{
			std::cout << keyCodes[i] << std::endl;
		}
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