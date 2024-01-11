#pragma once
#include <SDL2/SDL.h>

#include <Graphics/Rend.h>


namespace GEPEngine
{
	struct NativeWindow
	{
		~NativeWindow();

		SDL_Window* getWindow();
		SDL_GLContext getContext();

		bool setWindow(SDL_Window* _win);
		bool setContext(SDL_GLContext _con);

	private:
		SDL_Window* m_window;
		SDL_GLContext m_context;
	};
}