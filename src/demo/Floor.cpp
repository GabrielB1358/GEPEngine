#include "Floor.h"

namespace GEPEngine
{
	void Floor::initialise()
	{
		m_renderer = getEntity()->addComponent<ModelRenderer>();

		m_renderer->setModel("../Models/Floor/grassPlatform.obj");
		m_renderer->setTexture("../Textures/Floor/grassPlatformDiffuse.png");
		m_renderer->setShader("../Shaders/notGUI");
	}
}