#include <GEPEngine/Core.h>
#include "Entity.h"

namespace GEPEngine
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->onTick();
		}
	}

	void Entity::kill()
	{
		m_alive = false;
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