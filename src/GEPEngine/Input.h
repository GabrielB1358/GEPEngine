#pragma once

#include <memory>
#include <vector>
#include <GEPEngine/NativeWindow.h>

namespace GEPEngine
{
	enum Keys {
		leftM = SDL_BUTTON_LEFT,
		rightM = SDL_BUTTON_RIGHT,
		middleM = SDL_BUTTON_MIDDLE,

		gpadUp = SDL_CONTROLLER_BUTTON_DPAD_UP,
		gpadDown = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
		gpadLeft = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
		gpadRight = SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
		gpadStart = SDL_CONTROLLER_BUTTON_START,
		gpadBack = SDL_CONTROLLER_BUTTON_BACK,
		gpadLShoulder = SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
		gpadRShoulder = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
		gpadA = SDL_CONTROLLER_BUTTON_A,
		gpadB = SDL_CONTROLLER_BUTTON_B,
		gpadX = SDL_CONTROLLER_BUTTON_X,
		gpadY = SDL_CONTROLLER_BUTTON_Y,
		gpadStickX = SDL_CONTROLLER_AXIS_LEFTX,
		gpadStickY = SDL_CONTROLLER_AXIS_RIGHTX,

		w = SDLK_w,
		a = SDLK_a,
		s = SDLK_s,
		d = SDLK_d,
		b = SDLK_b,
		c = SDLK_c,
		e = SDLK_e,
		f = SDLK_f,
		g = SDLK_g,
		h = SDLK_h,
		i = SDLK_i,
		j = SDLK_j,
		k = SDLK_k,
		l = SDLK_l,
		m = SDLK_m,
		n = SDLK_n,
		o = SDLK_o,
		p = SDLK_p,
		q = SDLK_q,
		r = SDLK_r,
		t = SDLK_t,
		u = SDLK_u,
		v = SDLK_v,
		x = SDLK_x,
		y = SDLK_y,
		z = SDLK_z,

		zero = SDLK_0,
		one = SDLK_1,
		two = SDLK_2,
		three = SDLK_3,
		four = SDLK_4,
		five = SDLK_5,
		six = SDLK_6,
		seven = SDLK_7,
		eight = SDLK_8,
		nine = SDLK_9,
		uparrow = SDLK_UP,
		downarrow = SDLK_DOWN,
		leftarrow = SDLK_LEFT,
		rightarrow = SDLK_RIGHT,

		space = SDLK_SPACE,
		rshift = SDLK_RSHIFT,
		lshift = SDLK_LSHIFT,
		lcontrol = SDLK_LCTRL,
		enter = SDLK_EXECUTE
	};

	struct Core;
	struct Input
	{

		Input();

		void onTick();

		void processKeys(SDL_Event _e, glm::ivec2 _wSize);

		bool isKey(Keys keyCode);
		bool isKeyDown(Keys keyCode);
		bool isKeyUp(Keys keyCode);

		inline glm::vec2 getMouseMove() { return m_mouseMove; }

	private:

		std::vector<int> keyCodes;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;

		glm::vec2 m_mouseMove;
		glm::vec2 m_mouseCoords;
		bool lMouse, rMouse, mMouse;

		glm::vec2 gpMoveJoystick;
		glm::vec2 gpCamJoystick;
	};
}