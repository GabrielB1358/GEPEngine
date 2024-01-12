#include "Resource.h"

namespace GEPEngine
{
	void Resource::onLoad()
	{
		//When a resource is created, set its life time to 0
		m_lifeTime = 0;
	}

	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}

	float Resource::getLifeTime()
	{
		return m_lifeTime;
	}

	void Resource::setLifeTime(double _lt)
	{
		m_lifeTime = _lt;
	}
}