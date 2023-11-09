#pragma once

#include <memory>
#include <vector>
#include "Component.h"
#include <GEPEngine/NativeWindow.h>

namespace GEPEngine
{
	enum Keys {
		a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
		one, two, three, four, five, six, seven, eight, nine,
		uparrow, downarrow, leftarrow, rightarrow,
		space, rshift, lshift, lcontrol, enter
	};


	struct Core;
	struct Keyboard : Component
	{
		Keyboard();
		bool keyCodeLoop();

		bool isKey(Keys keyCode);
		bool isKeyDown(Keys keyCode);
		bool isKeyUp(Keys keyCode);

		void onTick() override;

		bool m_running;

	private:

		std::vector<int> keyCodes;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}