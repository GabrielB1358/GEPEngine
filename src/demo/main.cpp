#include <iostream>
#include <GEPEngine/MyEngine.h>

#undef main


using namespace GEPEngine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> entity = core->addEntity();

	std::shared_ptr<TriangleRenderer> component1 = entity->addComponent<TriangleRenderer>();
	std::shared_ptr<Transform> component2 = entity->addComponent<Transform>();

	core->start();

	return 0;
}