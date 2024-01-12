#pragma once
#include "Component.h"


namespace GEPEngine
{
	struct BoxCollider : Component
	{
		//Box Collider component contains information and functions for calculating and controlling entity collisions

		void initialise() override;

		bool colliding(glm::vec3 _pos, glm::vec3 _size);
		bool colliding(std::shared_ptr<BoxCollider> _other);
		bool checkCollision(glm::vec3 a, glm::vec3 b, glm::vec3 ahs, glm::vec3 bhs);

		glm::vec3 getCollisionResponse(glm::vec3 _pos, glm::vec3 _size);
		void getCollisionResponse(std::shared_ptr<Entity> _ent1, std::shared_ptr<Entity> _ent2);

		void setSize(glm::vec3 _size);
		void setOffset(glm::vec3 _offset);

		glm::vec3 getSize();
		glm::vec3 getOffset();
		glm::vec3 getPos();


	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;

		glm::vec3 m_newPos;
		glm::vec3 m_oldPos;
	};
}