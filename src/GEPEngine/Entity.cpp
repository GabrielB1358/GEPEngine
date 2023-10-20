#include <GEPEngine/Core.h>
#include "Entity.h"
#include "Component.h"

namespace GEPEngine
{
	Entity::Entity()
	{
		///hate

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
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->onDisplay();
		}
	}

	void Entity::kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			//m_components.at(ci)->kill();
		}
	}

	bool Entity::getAlive()
	{
		return m_alive;
	}
}