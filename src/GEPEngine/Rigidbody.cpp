#include "Rigidbody.h"
#include "Transform.h"
#include "Entity.h"

namespace GEPEngine
{
	void Rigidbody::onTick()
	{
		m_core = getCore();
		m_core->findColliders(m_colliders);

		//for (size_t i = 0; i < m_colliders.size(); i++)
		//{
		//	if (m_colliders.at(i)->getEntity() == getEntity())
		//		selfIndex = i;
		//}

		for (size_t i = 0; i < m_colliders.size(); i++)
		{
			if (m_colliders.at(i)->getEntity() == getEntity())
			{
				continue;
			}

			//if (i != selfIndex)
			{
				bool hit = m_colliders.at(i)->colliding(m_colliders.at(selfIndex)->getPosition(), m_colliders.at(selfIndex)->m_size);

				if (hit)
				{
					glm::vec3 displacement = m_colliders.at(i)->getCollisionResponse(m_colliders.at(i)->getPosition() + m_colliders.at(i)-> m_offset, m_colliders.at(i)->m_size);

					m_colliders.at(i)->getEntity()->getTransform()->Move(displacement - m_colliders.at(i)->m_offset);
				}
			}
		}
	}
}