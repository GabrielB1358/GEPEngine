#pragma once

#include <memory>
#include <vector>
#include <GEPEngine/NativeWindow.h>

namespace GEPEngine
{
	enum Keys {
		w = SDLK_w,
		a = SDLK_a,
		s = SDLK_s,
		d = SDLK_d,
		b,
		c,
		e,
		f,
		g,
		h,
		i,
		j,
		k,
		l,
		m,
		n,
		o,
		p = SDLK_p,
		q,r,t,u,v,x,y,z,
		one, two, three, four, five, six, seven, eight, nine,
		uparrow, downarrow, leftarrow, rightarrow,
		space = SDLK_SPACE, rshift, lshift = SDLK_LSHIFT, lcontrol, enter
	};


	struct Core;
	struct Keyboard
	{
		Keyboard();
		void processKeys(SDL_Event _e);

		bool isKey(Keys keyCode);
		bool isKeyDown(Keys keyCode);
		bool isKeyUp(Keys keyCode);

		void onTick();

		bool m_running;

		std::vector<int> keyCodes;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}