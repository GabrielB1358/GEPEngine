#include "NativeWindow.h"

namespace GEPEngine
{
	NativeWindow::~NativeWindow()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	SDL_Window* NativeWindow::getWindow()
	{
		return m_window;
	}

	SDL_GLContext NativeWindow::getContext()
	{
		return m_context;
	}

	bool NativeWindow::setWindow(SDL_Window* _win)
	{
		if (_win == NULL)
		{
			return false;
		}
		else
		{
			m_window = _win;
			return true;
		}
	}

	bool NativeWindow::setContext(SDL_GLContext _con)
	{
		if (_con == NULL)
		{
			return false;
		}
		else
		{
			m_context = _con;
			return true;
		}
	}
}