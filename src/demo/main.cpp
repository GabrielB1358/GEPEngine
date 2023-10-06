#include <iostream>
#include <GEPEngine/Core.h>


using namespace GEPEngine;

int main()
{
	//GEPEngine::Core core;

	std::shared_ptr<Core> core = Core::initialize();
	
	//std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent();

	return 0;
}