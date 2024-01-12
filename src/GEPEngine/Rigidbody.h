#pragma once
#include "Component.h"
#include "Core.h"
#include "BoxCollider.h"
#include <memory>
#include <vector>


namespace GEPEngine
{
	struct Rigidbody : Component
	{
		//Rigidbody component handles all the higher level parts of collisions
		//Holds all the colliders and acts on them

		void onTick();

		bool getColliding();

	private:
		int m_selfIndex;
		bool m_hit;
		std::vector<std::shared_ptr<BoxCollider> > m_colliders;
		std::shared_ptr<Core> m_core;
	};
}