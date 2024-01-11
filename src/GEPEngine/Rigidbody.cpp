#include "Rigidbody.h"
#include "Transform.h"
#include "Entity.h"

namespace GEPEngine
{
	void Rigidbody::onTick()
	{
		m_core = getCore();
		m_core->findColliders(m_colliders);

		for (size_t i = 0; i < m_colliders.size(); i++)
		{
			if (m_colliders.at(i)->getEntity() == getEntity())
			{
				continue;
			}

			std::shared_ptr<BoxCollider> collider = getEntity()->getComponent<BoxCollider>();

			//if (collider)
			//{
			//	bool hit = collider->colliding(m_colliders.at(i));
			//	if (hit)
			//	{
			//		glm::vec3 displacement = m_colliders.at(i)->getCollisionResponse(m_colliders.at(i)->getPos() + m_colliders.at(i)->getOffset(), m_colliders.at(i)->getSize());
			//		m_colliders.at(i)->getEntity()->getTransform()->Move(displacement - m_colliders.at(i)->getPos() - m_colliders.at(i)->getOffset());
			//	}
			//}

			if (collider)
			{
				bool hit = m_colliders.at(i)->colliding(collider);
				if (hit)
				{
					glm::vec3 displacement = collider->getCollisionResponse(collider->getPos() + collider->getOffset(), collider->getSize());
					collider->getEntity()->getTransform()->Move(displacement - collider->getPos() - collider->getOffset());
				}
			}
		}

		m_colliders.clear();
	}
}