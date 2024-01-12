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

	/***
	* Provides the main route of the engine
	*/
	struct Core
	{
		Core();
		~Core();

		/*******************************************************//**
		* The initialise function for the Core class
		* 
		* Initialises the SDL Window & Context as well as all the
		* other member variables crucial to runtime
		***********************************************************/
		static std::shared_ptr<Core> initialize();

		/*******************************************************//**
		* The start function for the Core class
		* 
		* Holds and executes the run loop of the game
		***********************************************************/
		void start();

		/*******************************************************//**
		* The function for adding entities to the game
		* 
		* Creates an entity, applies a reference to core and to self
		* then adds a transform before adding it to the entity
		* vector and returning a shared ptr of it
		***********************************************************/
		std::shared_ptr<Entity> addEntity();

		void setCamera(std::shared_ptr<Camera> _cam);//! Sets the camera variable
		void setPointLight(std::shared_ptr<Light> _light);//! sets the point light variable
		void setWinSize(glm::ivec2 _size);//! Sets the window size

		std::shared_ptr<GUI> getGUI();//! returns the GUI variable
		std::shared_ptr<Camera> getCamera();//! returns the camera variable
		std::shared_ptr<Input> getInput();//! returns the input variable
		std::shared_ptr<Resources> getResources();//! returns the resources variable
		std::shared_ptr<Environment> getEnvironment();//! returns the environment variable
		std::shared_ptr<Light> getPointLight();//! returns the point light variable
		glm::vec3 getLightPos();//! returns the light position vector
		glm::ivec2 getWinSize();//! returns the window size
		float getDT();//! returns delta time

		/*****************************************************************************//**
		* This function returns a vector of all present collider components
		* 
		* Cycles through all entities and for each it cycles through all
		* components and for those it checks for any BoxColliders and pushes
		* that collider into a vector before returning it
		* 
		* @param _out This is the vector you pass in and retrieve, filled with colliders
		*********************************************************************************/
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
		std::vector<std::shared_ptr<Entity> > m_entities; ///! stores all entities
		std::shared_ptr<NativeWindow> m_window; //! stores the native window variables for SDL window & context
		std::shared_ptr<Resources> m_resources; //! resources class variable holding the vector of resource type variables
		std::shared_ptr<GUI> m_GUI; //! Stores the GUI variable
		std::shared_ptr<Camera> m_camera; //! Stores the camera variable
		std::shared_ptr<Input> m_input; //! Stores the input variable
		std::shared_ptr<Environment> m_environment; //! Stores the environment variable
		std::shared_ptr<Light> m_pointLight; //! Stores the point light variable

		std::weak_ptr<Core> m_self; //! Stores a reference to self

		glm::ivec2 m_winSize; //! Stores the window size for resizable windows

		bool m_running = false; //! Bool variable for controlling the run loop
	};
}