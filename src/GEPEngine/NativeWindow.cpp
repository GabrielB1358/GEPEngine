#include "NativeWindow.h"

namespace GEPEngine
{
	NativeWindow::~NativeWindow()
	{
		//if alex is a bitch then leave this alone
		//(HE IS A BITCH)
		//ADD IF STATEMENTS TO MAKE THIS CLEANER
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}