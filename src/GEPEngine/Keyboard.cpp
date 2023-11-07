#include "Keyboard.h"

namespace GEPEngine
{
	Keyboard::Keyboard()
	{
		event = SDL_Event{ 0 };
	}

	void Keyboard::onTick()
	{
		//Poll stuff
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				pressedKeys.push_back(event.key.keysym.sym);
			}
			if (event.type == SDL_KEYUP)
			{
				releasedKeys.push_back(event.key.keysym.sym);
			}
			
			if (event.button.button == SDL_MOUSEBUTTONDOWN)
			{

			}
			if (event.button.button == SDL_MOUSEBUTTONUP)
			{

			}
		}

		pressedKeys.clear();
		releasedKeys.clear();
	}

	bool Keyboard::isKey(int keyCode)
	{
		return false;
	}

	bool Keyboard::isKeyDown(int keyCode)
	{
		return false;
	}

	bool Keyboard::isKeyUp(int keyCode)
	{
		return false;
	}
}