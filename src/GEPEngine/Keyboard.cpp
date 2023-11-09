#include "Keyboard.h"

namespace GEPEngine
{
	Keyboard::Keyboard()
	{
		m_running = true;
	}

	bool Keyboard::keyCodeLoop()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (std::find(keyCodes.begin(), keyCodes.end(), event.key.keysym.sym) != keyCodes.end())
				{
					continue;
				}
				else
				{
					keyCodes.push_back(event.key.keysym.sym);
					pressedKeys.push_back(event.key.keysym.sym);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				for (int i = 0; i < keyCodes.size(); i++)
				{
					if (keyCodes[i] == event.key.keysym.sym)
					{
						keyCodes.erase(keyCodes.begin() + i);
						releasedKeys.push_back(event.key.keysym.sym);
					}
				}
			}
		}
		return true;

	}

	void Keyboard::onTick()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				m_running = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (std::find(keyCodes.begin(), keyCodes.end(), event.key.keysym.sym) != keyCodes.end())
				{
					continue;
				}
				else
				{
					keyCodes.push_back(event.key.keysym.sym);
					pressedKeys.push_back(event.key.keysym.sym);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				for (int i = 0; i < keyCodes.size(); i++)
				{
					if (keyCodes[i] == event.key.keysym.sym)
					{
						keyCodes.erase(keyCodes.begin() + i);
						releasedKeys.push_back(event.key.keysym.sym);
					}
				}
			}
		}
	}

	//Make a function that converts from an SDL key to the Keys key
	//then use that in the find functions to make the keyboard work 

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