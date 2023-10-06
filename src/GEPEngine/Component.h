#include <memory>


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

	private:
		std::weak_ptr<Entity> entity;

		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();
	};
}