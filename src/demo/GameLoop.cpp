#include "GameLoop.h"
#include "billboard.h"
#include "Enemy.h"

namespace GEPEngine
{

	void GameLoop::initialise()
	{
		m_core = getCore();

		m_player = m_core->addEntity();
		m_floor = m_core->addEntity();
		m_billboard = m_core->addEntity();
		m_pointLight = m_core->addEntity();
		m_camera = m_core->addEntity();

		m_player->addComponent<Player>();
		m_player->addComponent<BoxCollider>();
		m_player->addComponent<Rigidbody>();
		m_player->SetPosition(glm::vec3(-2.5, 0, -10));

		m_floor->addComponent<Floor>();
		m_floor->addComponent<BoxCollider>();
		m_floor->getComponent<BoxCollider>()->setSize(glm::vec3(20, 1.0, 20));
		m_floor->SetPosition(glm::vec3(0, -2, -10));
		m_floor->getTransform()->setScale(glm::vec3(0.02, 0.02, 0.02));
		m_floor->getTransform()->setRotation(glm::vec3(-90.0f, 0.0f, 0.0f));

		m_billboard->addComponent<billboard>();
		m_billboard->SetPosition(glm::vec3(0.0f, 0, -12));
		m_billboard->getTransform()->setRotation(glm::vec3(135.0f, 0, 0));

		m_core->setPointLight(m_pointLight->addComponent<Light>());
		m_pointLight->SetPosition(glm::vec3(0, 5, -10));

		m_core->setCamera(m_camera->addComponent<Camera>());
		m_camera->SetPosition(glm::vec3(0.0f, 2, -4));

		m_entityTime = 0.0f;
		m_firstZSpawn = -8.0f;

		enemyDeathNum = 0;

		angle = 0;
	}

	void GameLoop::onTick()
	{
		m_entityTime += getDT();
		if (m_entityTime >= 2.0f)
		{	
			std::shared_ptr<Entity> tmp = m_core->addEntity();
			tmp->addComponent<Enemy>(getEntity()->getComponent<GameLoop>());
			tmp->addComponent<BoxCollider>();

			tmp->SetPosition(glm::vec3(2.8,-1.5,m_firstZSpawn));
			tmp->getTransform()->setRotation(glm::vec3(0, -90.0f, 0));
			m_entityTime = 0.0f;

			if (m_firstZSpawn == -12.0f)
			{
				m_firstZSpawn = -7.0f;
			}
			else
			{
				m_firstZSpawn -= 1.0f;
			}
		}
	}
}
