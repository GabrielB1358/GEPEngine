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
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Light> getLight();
		std::shared_ptr<Environment> getEnvironment();
		glm::vec3 getEntityPosition();
		double getDT();

		void tick();
		void display();
		void onInit();
		void onBegin();
		void kill();

		virtual void onTick();
		virtual void onDisplay();
		virtual void initialise();
		virtual void onGUI();
		virtual void onKill();

	private:
		friend struct Entity;
		std::weak_ptr<Entity> m_entity;
	};
}