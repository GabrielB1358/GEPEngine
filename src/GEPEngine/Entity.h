#pragma once
#include <memory>
#include <vector>
#include <GEPEngine/Transform.h>

namespace GEPEngine
{
	struct Core;
	struct Component;
	struct Transform;
	struct Camera;

	struct Entity
	{
		Entity();

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->initialise();
			m_components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			//Go through each component in entity
			for (size_t ci = 0; ci < m_components.size(); ++ci)
			{
				std::shared_ptr<Component> c = m_components.at(ci);

				//Try to dynamic cast the component to a T
				std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);

				//if it succeeds then add it to the output array
				if (t)
				{
					return t;
				}
			} 
		}

		std::shared_ptr<Transform> getTransform();

		std::shared_ptr<Core> getCore();
		void kill();
		bool getAlive();

		std::weak_ptr<Core> m_core;
		std::vector<std::shared_ptr<Component> > m_components;

	private:
		friend struct Core;

		void tick();
		void display();

		bool m_alive;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Transform> m_transform;
	};
}