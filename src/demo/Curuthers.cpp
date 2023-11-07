#include "Curuthers.h"
#include <GEPEngine/myEngine.h>


void Curuthers::initialise()
{
	m_renderer = m_entity.lock()->addComponent<GEPEngine::TriangleRenderer>();

	m_renderer->setModel("../Models/curuthers/curuthers.obj");
	m_renderer->setTexture("../Models/curuthers/Whiskers_diffuse.png");
	m_renderer->setShader("../Shaders/gui");

	
	angle = 0;
	m_entity.lock()->getTransform()->Move(glm::vec3(0, -0.5, -8));
}

void Curuthers::onTick()
{
	angle = 180 * getCore()->m_environment->getDT();
	m_entity.lock()->getTransform()->Rotate(glm::vec3(0, angle, 0));
}
