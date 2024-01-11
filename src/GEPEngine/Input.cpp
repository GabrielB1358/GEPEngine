#include "Input.h"
#define MAX_CONTROLLERS 1
SDL_GameController* ControllerHandles[MAX_CONTROLLERS];


namespace GEPEngine
{
	Input::Input()
	{
		int JStickNum = SDL_NumJoysticks();
		int controllerIndex = 0;
		for (size_t ji = 0; ji < JStickNum; ++ji)
		{
			if (!SDL_IsGameController(ji))
			{
				continue;
			}
			if (controllerIndex >= MAX_CONTROLLERS)
			{
				break;
			}
			ControllerHandles[controllerIndex] = SDL_GameControllerOpen(ji);
			controllerIndex++;
		}
	}

	Input::~Input()
	{
		for (int ji = 0; ji < MAX_CONTROLLERS; ++ji)
		{
			if (ControllerHandles[ji])
			{
				SDL_GameControllerClose(ControllerHandles[ji]);
			}
		}
	}

	void Input::onTick()
	{
		m_pressedKeys.clear();
		m_releasedKeys.clear();

		m_mouseMove = glm::vec2(0);
	}

	void Input::processKeys(SDL_Event _e, glm::ivec2 _wSize)
	{
		//Keyboard input processing
		if (_e.type == SDL_KEYDOWN)
		{
			if (std::find(m_keyCodes.begin(), m_keyCodes.end(), _e.key.keysym.sym) == m_keyCodes.end())
			{
				m_keyCodes.push_back(_e.key.keysym.sym);
				m_pressedKeys.push_back(_e.key.keysym.sym);
			}
		}
		else if (_e.type == SDL_KEYUP)
		{
			for (int i = 0; i < m_keyCodes.size(); i++)
			{
				if (m_keyCodes[i] == _e.key.keysym.sym)
				{
					m_keyCodes.erase(m_keyCodes.begin() + i);
					m_releasedKeys.push_back(_e.key.keysym.sym);
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

		}
		if (_e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (std::find(m_keyCodes.begin(), m_keyCodes.end(), _e.button.button) == m_keyCodes.end())
			{
				m_keyCodes.push_back(_e.button.button);
				m_pressedKeys.push_back(_e.button.button);
			}
		}
		else if (_e.type == SDL_MOUSEBUTTONUP)
		{
			for (int i = 0; i < m_keyCodes.size(); i++)
			{
				if (m_keyCodes[i] == _e.button.button)
				{
					m_keyCodes.erase(m_keyCodes.begin() + i);
					m_releasedKeys.push_back(_e.button.button);
				}
			}
		}

		//Gamepad input processing
		if (_e.type == SDL_JOYAXISMOTION)
		{
			if (_e.jaxis.which == 0)
			{
				if (_e.jaxis.axis == 0)
				{
					if (_e.jaxis.value > 3000 || _e.jaxis.value < -3000)
					{
						m_gpLeftJoystick.x = ((float)_e.jaxis.value / 32767.0f);
					}
					else
					{
						m_gpLeftJoystick.x = 0.0f;
					}
				}
				if (_e.jaxis.axis == 1)
				{
					if (_e.jaxis.value > 3000 || _e.jaxis.value < -3000)
					{
						m_gpLeftJoystick.y = ((float)_e.jaxis.value / 32767.0f);
					}
					else
					{
						m_gpLeftJoystick.y = 0.0f;
					}
				}
			}
			if (_e.jaxis.which == 1)
			{
				if (_e.jaxis.axis == 0)
				{
					if (_e.jaxis.value > 3000 || _e.jaxis.value < -3000)
					{
						m_gpRightJoystick.x = ((float)_e.jaxis.value / 32767.0f);
					}
					else
					{
						m_gpRightJoystick.x = 0.0f;
					}
				}
				if (_e.jaxis.axis == 1)
				{
					if (_e.jaxis.value > 3000 || _e.jaxis.value < -3000)
					{
						m_gpRightJoystick.y = ((float)_e.jaxis.value / 32767.0f);
					}
					else
					{
						m_gpRightJoystick.y = 0.0f;
					}
				}
			}
		}
		if (_e.type == SDL_CONTROLLERBUTTONDOWN || _e.type == SDL_JOYBUTTONDOWN)
		{
			if (std::find(m_keyCodes.begin(), m_keyCodes.end(), _e.button.button) == m_keyCodes.end())
			{
				m_keyCodes.push_back(_e.button.button);
				m_pressedKeys.push_back(_e.button.button);
			}
		}
		else if (_e.type == SDL_CONTROLLERBUTTONUP || _e.type == SDL_JOYBUTTONUP)
		{
			for (int i = 0; i < m_keyCodes.size(); i++)
			{
				if (m_keyCodes[i] == _e.button.button)
				{
					m_keyCodes.erase(m_keyCodes.begin() + i);
					m_releasedKeys.push_back(_e.button.button);
				}
			}
		}
	}

	glm::vec2 Input::getLeftJStick()
	{
		return m_gpLeftJoystick;
	}

	glm::vec2 Input::getRightJStick()
	{
		return m_gpRightJoystick;
	}

	glm::vec2 Input::getMouseMove()
	{
		return m_mouseMove;
	}

	glm::vec2 Input::getMouseCoords()
	{
		return m_mouseCoords;
	}

	bool Input::isKey(Keys keyCode)
	{
		if (std::find(m_keyCodes.begin(), m_keyCodes.end(), keyCode) != m_keyCodes.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Input::isKeyDown(Keys keyCode)
	{
		if (std::find(m_pressedKeys.begin(), m_pressedKeys.end(), keyCode) != m_pressedKeys.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Input::isKeyUp(Keys keyCode)
	{
		if (std::find(m_releasedKeys.begin(), m_releasedKeys.end(), keyCode) != m_releasedKeys.end())
		{
			return true;
		}
		else
			return false;
	}
}