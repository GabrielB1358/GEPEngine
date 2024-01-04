#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace GEPEngine
{
	bool BoxCollider::colliding(std::shared_ptr<BoxCollider> _other)
	{
		glm::vec3 a = m_entity.lock()->getTransform()->Position;
		glm::vec3 b = _other->getEntity()->getTransform()->Position;
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _other->m_size / 2.0f;

		return checkCollision(a, b, ahs, bhs);
	}

	bool BoxCollider::colliding(glm::vec3 _pos, glm::vec3 _size)
	{
		glm::vec3 a = getEntity()->getTransform()->Position;
		glm::vec3 b = _pos;
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _size / 2.0f;

		return checkCollision(a, b, ahs, bhs);
	}
	
	bool BoxCollider::checkCollision(glm::vec3 a, glm::vec3 b, glm::vec3 ahs, glm::vec3 bhs)
	{
		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
				return false;
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
				return false;
		}
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
				return false;
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
				return false;
		}
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
				return false;
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
				return false;
		}

		return true;
	}

	glm::vec3 BoxCollider::getCollisionResponse(glm::vec3 _pos, glm::vec3 _size)
	{
		//This is effectively the cludge method
		float amount = 0.01f;
		float step =   0.01f;

		while(true)
		{
 			if (!colliding(_pos, _size))
				break;
			_pos.x += amount;
			if (!colliding(_pos, _size))
				break;
			_pos.x -= amount;
			_pos.x -= amount;
			if (!colliding(_pos, _size))
				break;
			_pos.x += amount;
			_pos.z += amount;
			if (!colliding(_pos, _size))
				break;
			_pos.z -= amount;
			_pos.z -= amount;
			if (!colliding(_pos, _size))
				break;
			_pos.z += amount;
			_pos.y += amount;
			if (!colliding(_pos, _size))
				break;
			_pos.y -= amount;
			_pos.y -= amount;
			if (!colliding(_pos, _size))
				break;
			_pos.y += amount;
			
			amount += step;
			if (amount > 40)
			{
				break;
			}
		}

		return _pos;
	}

	void BoxCollider::setOffset(glm::vec3 _offset)
	{
		m_offset = _offset;
	}
	
	void BoxCollider::setSize(glm::vec3 _size)
	{
		m_size = _size;
	}

	glm::vec3 BoxCollider::getPosition()
	{
		return getEntity()->getTransform()->Position;
	}
}

