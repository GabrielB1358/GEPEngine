#pragma once
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>



namespace GEPEngine
{
	struct Core;
	struct Entity;
	struct Input;
	struct Light;
	struct MouseInput;
	struct Environment;
	struct Camera;

	struct Component
	{
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Light> getLight();
		std::shared_ptr<Environment> getEnvironment();
		double getDT();

		void onInit();
		void onBegin();

		virtual void onTick();
		virtual void onDisplay();
		virtual void initialise();


		std::weak_ptr<Entity> m_entity;

	private:
		void tick();
		void display();

		friend struct Entity;

	};
}