#include "evilBloke.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>


void evilBloke::initialise()
{
	m_renderer = getEntity()->addComponent<GEPEngine::ModelRenderer>();
	m_collider = getEntity()->addComponent<GEPEngine::BoxCollider>();

	m_renderer->setModel("../Models/absolutelyevilbloke/wendy_Scene.obj");
	m_renderer->setTexture("../Models/absolutelyevilbloke/blorger.png");
	m_renderer->setShader("../Shaders/notGUI");

	m_collider->setSize(glm::vec3(0.5f, 0.5f, 0.5f));
	m_collider->setOffset(glm::vec3(0));


	angle = 0;
	Move(glm::vec3(0, -0.5, -5));
	getEntity()->getTransform()->setScale(glm::vec3(1.0f, 3.0f, 1.0f));
}

void evilBloke::Move(glm::vec3 _move)
{
	getEntity()->getTransform()->Move(_move);
}

void evilBloke::onTick()
{
}
