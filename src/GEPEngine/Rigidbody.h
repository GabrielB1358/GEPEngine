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
		void onTick();

	private:
		int m_selfIndex;
		std::vector<std::shared_ptr<BoxCollider> > m_colliders;
		std::shared_ptr<Core> m_core;
	};
}