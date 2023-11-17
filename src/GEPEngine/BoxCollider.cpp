#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

bool GEPEngine::BoxCollider::colliding(const BoxCollider& _other)
{
	glm::vec3 a = m_entity.lock()->getTransform()->Position;
	glm::vec3 b = _other.m_entity.lock()->getTransform()->Position;
	glm::vec3 ahs = m_size / 2.0f;
	glm::vec3 bhs = _other.m_size / 2.0f;

	if (a.x > b.x)
	{
		if (a.x - ahs.x > b.x + bhs.x)
			return false;
	}
	else
	{
		if (b.x - bhs.x > a.x + ahs.x)
			return false;
	}
	if (a.z > b.z)
	{
		if (a.z - ahs.z > b.z + bhs.z)
			return false;
	}
	else
	{
		if (b.z - bhs.z > a.z + ahs.z)
			return false;
	}
	if (a.y > b.y)
	{
		if (a.y - ahs.y > b.y + bhs.y)
			return false;
	}
	else
	{
		if (b.y - bhs.y > a.y + ahs.y)
			return false;
	}

	return true;
}
