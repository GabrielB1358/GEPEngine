#pragma once
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace GEPEngine
{
	struct Core;
	struct Camera;
	struct Entity;
	struct Environment;
	struct Input;
	struct Light;
	struct MouseInput;

	struct Component
	{
		std::shared_ptr<Entity> getEntity(); //! returns the entity this component is attached to
		std::shared_ptr<Core> getCore(); //! returns the reference to core
		std::shared_ptr<Input> getInput(); //! returns the input reference through core
		std::shared_ptr<Light> getLight(); //! returns the light reference throug core
		std::shared_ptr<Environment> getEnvironment(); //! returns the environment reference through core
		glm::vec3 getEntityPosition(); //! returns the position of the entity this component is attached to
		double getDT(); //! returns delta time through Core->Evironment

		void tick(); //! Calls the virtual function onTick() which will be defined uniquely by each component class
		void display(); //! Calls the virtual function onDisplay() which will be defined uniquely by each component class
		void onInit(); //! Calls the virtual function initialise() which will be defined uniquely by each component class
		void kill(); //! Calls the virtual function onDisplay() which will be defined uniquely by each component class

		virtual void onTick(); //! virtual function defined uniquely in each component class
		virtual void onDisplay(); //! virtual function defined uniquely in each component class
		virtual void initialise(); //! virtual function defined uniquely in each component class
		virtual void onGUI(); //! virtual function defined uniquely in each component class
		virtual void onKill(); //! virtual function defined uniquely in each component class

	private:
		friend struct Entity;
		std::weak_ptr<Entity> m_entity; //! reference to entity this component is attached to
	};
}