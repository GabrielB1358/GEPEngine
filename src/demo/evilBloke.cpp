#include "evilBloke.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Keyboard.h>


void evilBloke::initialise()
{
	m_renderer = m_entity.lock()->addComponent<GEPEngine::ModelRenderer>();

	m_renderer->setModel("../Models/absolutelyevilbloke/wendy_Scene.obj");
	m_renderer->setTexture("../Models/absolutelyevilbloke/blorger.png");
	m_renderer->setShader("../Shaders/gui");


	angle = 0;
	m_entity.lock()->getTransform()->Move(glm::vec3(0, -0.5, -5));
	m_entity.lock()->getTransform()->Scale = glm::vec3(1.0f, 3.0f, 1.0f);
}

void evilBloke::Move(glm::vec3 _move)
{
}

void evilBloke::onTick()
{
}
