#include <memory>
#include <vector>
#include <GEPEngine/Transform.h>

namespace GEPEngine
{
	struct Core;
	struct Component;
	struct Transform;

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

		std::shared_ptr<Core> getCore();
		void kill();
		bool getAlive();

		std::shared_ptr<Transform> m_Transform;
		std::weak_ptr<Core> m_core;

	private:
		friend struct Core;

		void tick();
		void display();

		bool m_alive;
		std::vector<std::shared_ptr<Component> > m_components;
		std::weak_ptr<Entity> m_self;
	};
}