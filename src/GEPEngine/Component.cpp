#include "Component.h"
#include "Entity.h"


namespace GEPEngine
{
	void Component::initialise()
	{

	}

	void Component::onInit()
	{
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
	std::shared_ptr<Core> Component::getCore()
	{
		return m_entity.lock()->getCore();
	}
	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return std::shared_ptr<Keyboard>();
	}
	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return std::shared_ptr<Environment>();
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
		onDisplay();
	}
	void Component::onTick()
	{
	}
	void Component::onDisplay()
	{
	}
}
