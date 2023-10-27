#include <memory>

namespace GEPEngine
{
	struct Core;

	struct Environment
	{
		void Init();

		void Tick();

		float getDT();

	private:
		float deltaTime = 0;
		float last = 0;
	};
}