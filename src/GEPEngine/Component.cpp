#include "Component.h"
#include "Entity.h"
#include "Core.h"



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
		return getCore()->m_keyboard;
	}
	std::shared_ptr<MouseInput> Component::getMouseInput()
	{
		return getCore()->m_mouseInput;
	}
	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return std::shared_ptr<Environment>();
	}
	double Component::getDT()
	{
		return 0.0;
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
