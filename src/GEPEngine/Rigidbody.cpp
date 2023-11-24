#include "Rigidbody.h"

namespace GEPEngine
{
	void Rigidbody::onTick()
	{
		m_core = getCore();
		m_core->findColliders(m_colliders);
	}
}