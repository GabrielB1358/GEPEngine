#include <iostream>
#include <GEPEngine/TriangleRenderer.h>
#include <GEPEngine/Core.h>
//make mega header
#include <GEPEngine/TriangleRenderer.h>
#include <GEPEngine/Entity.h>

#undef main


using namespace GEPEngine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent();
	std::shared_ptr<TriangleRenderer> component2 = entity->addComponent<TriangleRenderer>();

	core->start();

	return 0;
}