#include <memory>

namespace GEPEngine
{
	struct Core;

	struct Environment
	{
		//Environment class controls the passage of time through the game loop, holding the delta time value between frames
		void Init();
		void Tick();

		double getDT();

	private:
		double m_deltaTime = 0;
		double m_last = 0;
	};
}