#pragma once
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace GEPEngine
{
	struct Core;
	struct Entity;
	struct Keyboard;
	struct Environment;

	struct Component
	{
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Environment> getEnvironment();

		void onInit();
		void onBegin();

		virtual void onTick();
		virtual void onDisplay();
		//void kill();
		virtual void initialise();

	private:
		void tick();
		void display();

		friend struct Entity;
		std::weak_ptr<Entity> m_entity;

	};
}