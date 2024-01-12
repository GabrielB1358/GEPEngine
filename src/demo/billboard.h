
#include <GEPEngine/Component.h>
namespace GEPEngine
{
	struct QuadRenderer;
	struct billboard : Component
	{

		void initialise();

	private:
		std::shared_ptr<QuadRenderer> m_renderer;
	};
}