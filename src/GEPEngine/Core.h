#pragma once
#include <iostream>
#include <GEPEngine/Resources.h>
#include <GEPEngine/Environment.h>
#include <GEPEngine/Keyboard.h>

namespace GEPEngine
{
	struct Entity;
	struct Component;


	struct Core
	{
		Core();
		~Core();

		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Resources> getResources();

		void start();
		void stop();

		std::shared_ptr<Entity> addEntity();

		template <typename T>
		std::shared_ptr<T> addComponent() { }

		std::shared_ptr<Environment> m_environment;
		std::shared_ptr<Keyboard> m_keyboard;

	private:
		std::shared_ptr<NativeWindow> m_window;
		friend struct entity;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Resources> m_resources;
		std::weak_ptr<Core> m_self;

		//SDL_Window* m_nativeWindow;
		bool m_running = false;
	};
}