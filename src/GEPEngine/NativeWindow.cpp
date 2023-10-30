#include "NativeWindow.h"

namespace GEPEngine
{
	NativeWindow::~NativeWindow()
	{
		//ADD IF STATEMENTS TO MAKE THIS CLEANER
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}