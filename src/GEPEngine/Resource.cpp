#include "Resource.h"

namespace GEPEngine
{
	void Resource::onLoad()
	{
		lifeTime = 0;
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
		return lifeTime;
	}

	void Resource::setLifeTime(double _lt)
	{
		lifeTime = _lt;
	}
}