#include "Keyboard.h"

namespace GEPEngine
{
	Keyboard::Keyboard()
	{
		m_running = true;
	}

	void Keyboard::processKeys(SDL_Event _e)
	{
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
	}

	void Keyboard::onTick()
	{
		pressedKeys.clear();
		releasedKeys.clear();
	}

	bool Keyboard::isKey(Keys keyCode)
	{
		if (std::find(keyCodes.begin(), keyCodes.end(), keyCode) != keyCodes.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Keyboard::isKeyDown(Keys keyCode)
	{
		if (std::find(pressedKeys.begin(), pressedKeys.end(), keyCode) != pressedKeys.end())
		{
			return true;
		}
		else
			return false;
	}

	bool Keyboard::isKeyUp(Keys keyCode)
	{
		if (std::find(releasedKeys.begin(), releasedKeys.end(), keyCode) != releasedKeys.end())
		{
			return true;
		}
		else
			return false;
	}
}