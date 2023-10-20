#include "Component.h"


namespace GEPEngine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		//TODO
		//THESE WILL RETURN NULL POINTERS
		//RETURN m_Entity

		return std::shared_ptr<Entity>();
	}
	std::shared_ptr<Core> Component::getCore()
	{
		return std::shared_ptr<Core>();
	}
	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return std::shared_ptr<Keyboard>();
	}
	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return std::shared_ptr<Environment>();
	}
	void Component::onInit()
	{
	}
	void Component::onBegin()
	{
	}
	void Component::tick()
	{
		onTick();
	}
	void Component::display()
	{
	}
	void Component::onTick()
	{
	}
	void Component::onDisplay()
	{
	}
	void Component::initialise()
	{
	}
}
