#pragma once
#include <iostream>
#include <GEPEngine/NativeWindow.h>
#include <GEPEngine/Resources.h>
#include <GEPEngine/Environment.h>

namespace GEPEngine
{
	struct Entity;
	struct Component;
	struct Keyboard;
	struct Environment;


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

	private:
		std::shared_ptr<NativeWindow> m_window;
		friend struct entity;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Keyboard> keyboard;
		std::weak_ptr<Core> m_self;

		//SDL_Window* m_nativeWindow;
		bool m_running = false;
	};
}