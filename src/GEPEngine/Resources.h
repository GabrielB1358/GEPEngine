#pragma once
#include "Resource.h"
#include <memory>
#include <string>
#include <vector>

namespace GEPEngine
{
	struct Core;
	struct Resources
	{
		//Resources class handles the loading of resources through a file path
		//Handles their creation or acquisition of resources

		void onTick();
		void initialise(std::shared_ptr<Core> _core);

		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			//Search for the resource already preloaded
			for (size_t i = 0; i < m_resources.size(); i++)
			{
				//If its preloaded then return it
				if (m_resources.at(i)->getPath() == _path)
				{
					m_resources.at(i)->setLifeTime(0.0f);
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}

			//If its not preloaded then make one and return it
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->setLifeTime(0.0f);
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;

		}

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::vector<std::string> m_dirtyFlags;
		std::shared_ptr<Core> m_core; // Reference to core for delta time access
	};
}