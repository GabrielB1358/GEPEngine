#include "billboard.h"

namespace GEPEngine
{

	void billboard::initialise()
	{
		m_renderer = getEntity()->addComponent<QuadRenderer>();

		m_renderer->setTexture("../Billboard.png");
		m_renderer->setShader("../Shaders/notGUI");
	}
}