#include <memory>

namespace GEPEngine
{
	struct Core;

	struct Environment
	{
		float getDeltaTime();

	private:
		float deltaTime;
	};
}