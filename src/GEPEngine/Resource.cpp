#include "Resource.h"

namespace GEPEngine
{
	void Resource::onLoad()
	{
	}

	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}

}