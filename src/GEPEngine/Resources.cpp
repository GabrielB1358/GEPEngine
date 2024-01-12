#include "Resources.h"
#include "Core.h"

namespace GEPEngine
{
	void Resources::initialise(std::shared_ptr<Core> _core)
	{
		m_core = _core;
	}

	void Resources::onTick()
	{
		//Cycle through resources and for resources exceeding the max life time, flag them for death
		for (size_t ri = 0; ri < m_resources.size(); ri++)
		{
			if (m_resources.at(ri)->getLifeTime() > 60.0f)
			{
				m_dirtyFlags.push_back(m_resources.at(ri)->m_path);
			}
			else
			{
				m_resources.at(ri)->m_lifeTime += m_core->getDT();
			}
		}

		//Go through list of dirty flags and delete their corresponding resource
		while (m_dirtyFlags.size() > 0)
		{
			std::string path = m_dirtyFlags[0];

			for (int ri = 0; ri < m_resources.size(); ri++)
			{
				if (m_resources.at(ri)->getPath() == path)
				{
					m_resources.erase(find(m_resources.begin(), m_resources.end(), m_resources.at(ri)));
					std::cout << "Erased: " << path << std::endl;
					m_dirtyFlags.erase(m_dirtyFlags.begin());
				}
				
			}
		}
	}

}