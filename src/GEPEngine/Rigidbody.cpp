#include "Rigidbody.h"
#include "Transform.h"
#include "Entity.h"

namespace GEPEngine
{
	void Rigidbody::onTick()
	{
		//Get core reference and fill collider vector
		m_core = getCore();
		m_core->findColliders(m_colliders);

		std::shared_ptr<BoxCollider> collider = getEntity()->getComponent<BoxCollider>();

		//Cycle through all colliders and do collisions between them
		for (size_t i = 0; i < m_colliders.size(); i++)
		{
			//Ignore if trying to collide with self
			if (m_colliders.at(i)->getEntity() == getEntity())
			{
				continue;
			}

			//If this entitys collider is valid then check for collision between self and the entity
			if (collider)
			{
				bool hit = collider->colliding(m_colliders.at(i));
			
				if (hit)
				{
					std::cout << hit << std::endl;
					collider->getCollisionResponse(collider->getEntity(), m_colliders.at(i)->getEntity());

					//OLD - USING KLUDGE METHOD
					//glm::vec3 displacement = collider->getCollisionResponse(collider->getPos() + collider->getOffset(), collider->getSize());
					//collider->getEntity()->getTransform()->Move(displacement - collider->getPos() - collider->getOffset());
				}
			}
		}

		//Empty colliders each tick
		m_colliders.clear();
	}
}