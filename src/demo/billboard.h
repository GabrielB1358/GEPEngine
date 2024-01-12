#include <GEPEngine/Component.h>
#include <GEPEngine/QuadRenderer.h>

namespace GEPEngine
{

	struct billboard : Component
	{

		void initialise();

	private:
		std::shared_ptr<QuadRenderer> m_renderer;
	};
}