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
		void onTick();

		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			//Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); i++)
			{
				//return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					m_resources.at(i)->setLifeTime(0.0f);
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
				else
				{
					//this means the resource couldnt be loaded
					//Wrap an exception thing around this

				}
			}

			//OR
			//try
			//{
			//}
			//catch
			//{
			//}

			//Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->lifeTime = 0.0f;
			rtn->load();
			m_resources.push_back(rtn);

			return rtn;
		}

		void initialise(std::shared_ptr<Core> _core);

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::vector<std::string> m_dirtyFlags;
		std::shared_ptr<Core> m_core;
	};
}