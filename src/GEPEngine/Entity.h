#pragma once
#include <GEPEngine/Transform.h>
#include <memory>
#include <vector>

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

		template <typename T, typename U>
		std::shared_ptr<T> addComponent(U _u)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->initialise(_u);
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

		void Move(glm::vec3 _pos);
		void SetPosition(glm::vec3 _pos);

		std::shared_ptr<Transform> getTransform();
		std::shared_ptr<Core> getCore();
		glm::vec3 getPosition();
		bool getAlive();
		float getDT();

		void tick();
		void display();
		void kill();
		void onGUI();

		void endFrame();

	private:
		friend struct Core;
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Transform> m_transform;
		std::vector<std::shared_ptr<Component> > m_components;
		bool m_alive;
	};
}