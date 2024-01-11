#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "GUI.h"

namespace GEPEngine
{
	Core::Core()
	{
	}

	Core::~Core()
	{
		SDL_GL_DeleteContext(m_window->getContext());
		SDL_DestroyWindow(m_window->getWindow());
		SDL_Quit();
	}

	//GETTER FUNCTIONS

	std::shared_ptr<Core> Core::initialize()
	{
		//Setting up core and the window
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_winSize = glm::ivec2(1920, 1080);
		rtn->m_window = std::make_shared<NativeWindow>();
		rtn->m_resources = std::make_shared<Resources>();
		rtn->m_GUI = std::make_shared<GUI>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		//Initialise SDL
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		//Create a window and assign to window variable
		if (!rtn->m_window->setWindow(SDL_CreateWindow("SDL2 Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rtn->m_winSize.x, rtn->m_winSize.y, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create window");
		}

		//Create GL context for the window
		if (!rtn->m_window->setContext(SDL_GL_CreateContext(rtn->m_window->getWindow())))
		{
			SDL_DestroyWindow(rtn->m_window->getWindow());
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}


		glewInit();

		//						====== AUDIO SETUP ======

		ALCdevice* m_aDevice;
		ALCcontext* m_aContext;

		m_aDevice = alcOpenDevice(NULL);

		if (!m_aDevice)
		{
			throw std::runtime_error("Couldn't open audio device");
		}

		m_aContext = alcCreateContext(m_aDevice, NULL);

		if (!m_aContext)
		{
			alcCloseDevice(m_aDevice);
			throw std::runtime_error("Couldn't create audio context");
		}

		if (!alcMakeContextCurrent(m_aContext))
		{
			alcDestroyContext(m_aContext);
			alcCloseDevice(m_aDevice);
			throw std::runtime_error("Couldn't make context current");
		}

		rtn->m_GUI->initialise(rtn);
		rtn->m_resources->initialise(rtn);
		return rtn;
	}

	void Core::start()
	{
		m_running = true;
		SDL_Event event = { 0 };

		//Setup the environment to access DeltaTime
		m_environment = std::make_shared<Environment>();
		m_environment->Init();

		m_input = std::make_shared<Input>();


		while (m_running)
		{
			//Updates window size for mouse and consequently camera (ONLY FOR IF MOUSE IS CONTROLLING CAM)
			//SDL_GetWindowSize(m_window->window, &winSize.x, &winSize.y);

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
				m_input->processKeys(event, m_winSize);
			}


			//Tick and display all entities
			for (int i = 0; i < m_entities.size();i++)
			{
				try
				{
					m_entities[i]->tick();
				}
				catch(std::exception &m_e)
				{
					m_entities[i]->kill();
				}
			}
			for (int i = 0; i < m_entities.size(); i++)
			{
				m_entities[i]->display();
			}
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities[i]->onGUI();
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

			//Ticks resources to increase their timer
			m_resources->onTick();

			//tick keyboard, clearing the key vectors
			m_input->onTick();
			SDL_GL_SwapWindow(m_window->getWindow());
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

	std::shared_ptr<Resources> Core::getResources()
	{
		return m_resources;
	}

	std::shared_ptr<GUI> Core::getGUI()
	{
		return m_GUI;
	}

	float Core::getDT()
	{
		return m_environment->getDT();
	}

	glm::vec3 Core::getLightPos()
	{
		return m_pointLight->getPos();
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return m_camera;
	}

	void Core::setCamera(std::shared_ptr<Camera> _cam)
	{
		m_camera = _cam;
	}

	std::shared_ptr<Input> Core::getInput()
	{
		return m_input;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return m_environment;
	}

	std::shared_ptr<Light> Core::getPointLight()
	{
		return m_pointLight;
	}

	void Core::setPointLight(std::shared_ptr<Light> _light)
	{
		m_pointLight = _light;
	}

	void Core::setWinSize(glm::ivec2 _size)
	{
		m_winSize = _size;
	}

	glm::ivec2 Core::getWinSize()
	{
		return m_winSize;
	}
}