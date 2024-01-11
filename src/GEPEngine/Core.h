#pragma once
#include <GEPEngine/ALSoundSrc.h>
#include <GEPEngine/BoxCollider.h>
#include <GEPEngine/Camera.h>
#include <GEPEngine/Environment.h>
#include <GEPEngine/Input.h>
#include <GEPEngine/Light.h>
#include <GEPEngine/Resources.h>
#include <iostream>


namespace GEPEngine
{
	struct Entity;
	struct Component;
	struct GUI;

	struct Core
	{
		Core();
		~Core();

		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> addEntity();

		void setCamera(std::shared_ptr<Camera> _cam);
		void setPointLight(std::shared_ptr<Light> _light);
		void setWinSize(glm::ivec2 _size);

		std::shared_ptr<GUI> getGUI();
		std::shared_ptr<Camera> getCamera();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Environment> getEnvironment();
		std::shared_ptr<Light> getPointLight();
		glm::vec3 getLightPos();
		glm::ivec2 getWinSize();
		float getDT();

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

	private:
		friend struct entity;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::shared_ptr<NativeWindow> m_window;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<BoxCollider> m_boxColliders;
		std::shared_ptr<GUI> m_GUI;
		std::shared_ptr<Camera> m_camera;
		std::shared_ptr<Input> m_input;
		std::shared_ptr<Environment> m_environment;
		std::shared_ptr<Light> m_pointLight;

		std::weak_ptr<Core> m_self;

		glm::ivec2 m_winSize;

		bool m_running = false;
	};
}