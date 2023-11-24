#pragma once
#include <iostream>
#include <GEPEngine/Resources.h>
#include <GEPEngine/Environment.h>
#include <GEPEngine/Keyboard.h>
#include <GEPEngine/BoxCollider.h>

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

		std::shared_ptr<Entity> addEntity();

		template <typename T>
		std::shared_ptr<T> addComponent() { }

		template <typename T>
		void findColliders(std::vector<std::shared_ptr<T> >& _out);

		std::shared_ptr<Environment> m_environment;
		std::shared_ptr<Keyboard> m_keyboard;

	private:
		std::shared_ptr<NativeWindow> m_window;
		friend struct entity;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<BoxCollider> m_boxColliders;
		std::weak_ptr<Core> m_self;

		//SDL_Window* m_nativeWindow;
		bool m_running = false;
	};
}