#include "Entity.h"
#include "Core.h"



namespace GEPEngine
{
	void Component::initialise()
	{

	}

	void Component::onGUI()
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
	std::shared_ptr<Input> Component::getInput()
	{
		return getCore()->getInput();
	}
	std::shared_ptr<Light> Component::getLight()
	{
		return getCore()->getPointLight();
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
	void Component::kill()
	{
		onKill();
	}
	void Component::onTick()
	{
	}
	void Component::onDisplay()
	{
	}
	void Component::onKill()
	{
	}
}
