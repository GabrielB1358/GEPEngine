#include <iostream>
#include <memory>
#include <vector>

namespace GEPEngine
{
	struct Entity;
	struct Component;
	struct Keyboard;
	struct Environment;


	struct Core
	{
		void start();
		void stop();

		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Environment> environment;
		std::shared_ptr<Keyboard> keyboard;
		std::weak_ptr<Core> m_self;

		//SDL_Window* m_nativeWindow;
		bool m_running = false;
	};
}