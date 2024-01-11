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
		for (size_t ri = 0; ri < m_resources.size(); ri++)
		{
			if (m_resources.at(ri)->getLifeTime() > 3.0f)
			{
				m_dirtyFlags.push_back(m_resources.at(ri)->m_path);
			}
			else
			{
				m_resources.at(ri)->lifeTime += m_core->getDT();
			}
		}

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