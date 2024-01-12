#include "Enemy.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>


void Enemy::initialise()
{
	m_renderer = getEntity()->addComponent<GEPEngine::ModelRenderer>();

	m_renderer->setModel("../Models/Enemy/wendy_Scene.obj");
	m_renderer->setTexture("../Textures/Enemy/blorger.png");
	m_renderer->setShader("../Shaders/notGUI");

	getEntity()->getTransform()->setScale(glm::vec3(1.0f,3.0f,1.0f));
}

void Enemy::Move(glm::vec3 _move)
{
	getEntity()->getTransform()->Move(_move);
}

void Enemy::onTick()
{
	//Move(glm::vec3(getCore()->getDT() * 1.0));

}
