#include "Core.h"
#include "Entity.h"
#include "Transform.h"

namespace GEPEngine
{
	Core::Core()
	{

	}

	Core::~Core()
	{
		SDL_GL_DeleteContext(m_window->context);
		SDL_DestroyWindow(m_window->window);
		SDL_Quit();
	}

	//GETTER FUNCTIONS

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_window = std::make_shared<NativeWindow>();
		rtn->m_resources = std::make_shared<Resources>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		//Initialise SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		//Create a window and assign to window variable
		if (!(rtn->m_window->window = SDL_CreateWindow("SDL2 Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create window");
		}

		//Create GL context for the window
		if (!(rtn->m_window->context = SDL_GL_CreateContext(rtn->m_window->window)))
		{
			SDL_DestroyWindow(rtn->m_window->window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}

		glewInit();

		return rtn;
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return m_resources;
	}

	void Core::start()
	{
		m_running = true;
		SDL_Event event = { 0 };

		//Setup the environment to access DeltaTime
		m_environment = std::make_shared<Environment>();
		m_environment->Init();

		m_keyboard = std::make_shared<Keyboard>();


		while (m_running)
		{
			//Tick Environment, updating deltatime
			m_environment->Tick();


			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5, 0, 1, 1);

			//Poll keyboard inputs and attend to appropriate vectors
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				{
					m_running = false;
				}
				m_keyboard->processKeys(event);
			}

			//Tick and display all entities
			for (int i = 0; i < m_entities.size();i++)
			{
				m_entities[i]->tick();
			}
			for (int i = 0; i < m_entities.size(); i++)
			{
				m_entities[i]->display();
			}

			//Kills any entities that are no longer alive
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				if (!m_entities[ei]->getAlive())
				{
					m_entities.erase(m_entities.begin() + ei);
					--ei;
				}
			}


			//tick keyboard, clearing the key vectors
			m_keyboard->onTick();
			SDL_GL_SwapWindow(m_window->window);
		}
	}

	template <typename T>
	void findColliders(std::vector<std::shared_ptr<T> >& _out)
	{
		//Go through each entity in core
		for (size_t i = 0; i < m_entities.size(); i++)
		{
			std::shared_ptr<Entity> e = _entities.at(i);
			
			//Go through each component in entity
			for (size_t ei = 0; ei < e->m_components.size(); ei++)
			{
				std::shared_ptr<Component> c = e->m_components.at(ei);

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

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		

		rtn->m_core = m_self;
		rtn->m_self = rtn;
		rtn->m_transform = rtn->addComponent<Transform>();

		m_entities.push_back(rtn);

		return rtn;
	}
}