#include <GEPEngine/Core.h>
#include "Entity.h"
#include "Component.h"

namespace GEPEngine
{
	Entity::Entity()
	{
	}

	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::display()
	{
		if(m_alive)
		{
			for (size_t ci = 0; ci < m_components.size(); ci++)
			{
				m_components.at(ci)->display();
			}
		}
	}

	void Entity::kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->kill();
		}
	}

	bool Entity::getAlive()
	{
		return m_alive;
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	void Entity::onGUI()
	{
		if(m_alive)
		{
			for (size_t i = 0; i < m_components.size(); i++)
			{
				m_components[i]->onGUI();
			}
		}
	}

	void Entity::Move(glm::vec3 _pos)
	{
		getTransform()->Move(_pos);
	}

	void Entity::SetPosition(glm::vec3 _pos)
	{
		getTransform()->setPosition(_pos);
		
	}
}