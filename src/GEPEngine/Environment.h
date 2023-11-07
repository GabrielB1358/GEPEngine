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
		double deltaTime = 0;
		double last = 0;
	};
}