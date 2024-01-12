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

		/*******************************************************//**
		* Function for attaching components to an entity
		*
		* Creates a component that could be of multiple types
		* sets the entity reference on it to self, calls initialise
		* on it and then returns it
		***********************************************************/
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->initialise();
			m_components.push_back(rtn);

			return rtn;
		}

		/******************************************************************************//**
		* Overloaded function for adding a component
		*
		* This function also creates a component that could be of 
		* many different types, sets entity reference and calls
		* initialise but passing it a parameter this time
		*
		* @param _u This is the multi-type input parameter used in the initialise function
		**********************************************************************************/
		template <typename T, typename U>
		std::shared_ptr<T> addComponent(U _u)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->initialise(_u);
			m_components.push_back(rtn);

			return rtn;
		}

		/*******************************************************//**
		* A function for returning a specific component
		*
		* loops through all components and compares their type to
		* the given, desired type and returns a shared pointer
		* of that component if found
		***********************************************************/
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

		void Move(glm::vec3 _pos); //! Increments position by amount in parameter
		void SetPosition(glm::vec3 _pos); //! Sets position to value in parameter

		std::shared_ptr<Transform> getTransform(); //! Returns reference to transform component
		std::shared_ptr<Core> getCore(); //! Returns reference to core
		glm::vec3 getPosition(); //! Returns position through transform
		bool getAlive(); //! Returns alive bool
		float getDT(); //! returns delta time through Core->Environment

		void tick(); //! Called every tick but just calls tick for all attached components
		void display(); //! Called every tick and calls display for all attached components
		void kill(); //! Sets alive flag to false and calls kill on all attached components
		void onGUI(); //! Called every tick and calls onGUI for all attached components

		void endFrame(); //! Called every tick but only calls it for transform component

	private:
		friend struct Core;
		std::weak_ptr<Core> m_core; //! reference to core
		std::weak_ptr<Entity> m_self; //! reference to self for child classes
		std::weak_ptr<Transform> m_transform; //! transform component for controlling movememnt
		std::vector<std::shared_ptr<Component> > m_components; //! vector for storing all components on this entity
		bool m_alive; //! alive flag is used to control the continuity of this entity
	};
}