#include <memory>

namespace GEPEngine
{
	struct Core;

	struct Environment
	{
		void Init();
		void Tick();

		double getDT();

	private:
		double m_deltaTime = 0;
		double m_last = 0;
	};
}