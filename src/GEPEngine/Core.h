#pragma once
#include <iostream>
#include <GEPEngine/Resources.h>
#include <GEPEngine/Environment.h>
#include <GEPEngine/Keyboard.h>
#include <GEPEngine/BoxCollider.h>
#include <GEPEngine/ALSoundSrc.h>

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
		std::shared_ptr<T> addComponent()
		{

		}

		template <typename T>
		void findColliders(std::vector<std::shared_ptr<T> >& _out)
		{
			//Go through each entity in core
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);

				//Go through each component in entity
				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);

					//Try to dynamic cast the component to a T
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);

					//if it succeeds then add it to the output array
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

		std::shared_ptr<Environment> m_environment;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<ALAudio> m_Audio;

		//static ALCdevice* aDevice;
		//static ALCcontext* aContext;


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