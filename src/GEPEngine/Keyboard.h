#pragma once

#include <memory>
#include <vector>
#include "Component.h"
#include <GEPEngine/NativeWindow.h>

namespace GEPEngine
{
	enum Keys {
		w,
		a,
		s,
		d
	};

	enum Buttons {
		Forward,
		Backward,
		Left,
		Right
	};

	struct Core;
	struct Keyboard : Component
	{
		Keyboard();

		bool isKey(int keyCode);
		bool isKeyDown(int keyCode);
		bool isKeyUp(int keyCode);

	private:
		void onTick() override;

		SDL_Event event;

		std::vector<int> keyCodes;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}