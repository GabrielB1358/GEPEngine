#pragma once
#include <SDL2/SDL.h>

#include <Graphics/Rend.h>


namespace GEPEngine
{
	struct NativeWindow
	{

		SDL_Window* window;
		SDL_GLContext context;

		~NativeWindow();
	};
}