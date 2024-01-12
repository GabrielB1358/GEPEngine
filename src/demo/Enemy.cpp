#include "Enemy.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>
#include <GEPEngine/Rigidbody.h>
#include "GameLoop.h"


void Enemy::initialise(std::shared_ptr<GEPEngine::GameLoop> _gl)
{
	m_gameLoop = _gl;

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
	Move(glm::vec3(-(getCore()->getDT()), 0, 0));

	if (getEntity()->getPosition().x <= -2.8f)
	{
		m_gameLoop->enemyDeathNum++;
		getEntity()->kill();
	}
}
