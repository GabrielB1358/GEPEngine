#include "evilBloke.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>


void evilBloke::initialise()
{
	m_renderer = getEntity()->addComponent<GEPEngine::ModelRenderer>();

	m_renderer->setModel("../Models/absolutelyevilbloke/wendy_Scene.obj");
	m_renderer->setTexture("../Models/absolutelyevilbloke/blorger.png");
	m_renderer->setShader("../Shaders/notGUI");

	getEntity()->getTransform()->setScale(glm::vec3(1.0f,3.0f,1.0f));
}

void evilBloke::Move(glm::vec3 _move)
{
	getEntity()->getTransform()->Move(_move);
}

void evilBloke::onTick()
{
}
