#include <iostream>
#include <GEPEngine/MyEngine.h>
#include "Curuthers.h"

#undef main


using namespace GEPEngine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> entity = core->addEntity();

	std::shared_ptr<Curuthers> cat = entity->addComponent<Curuthers>();

	core->start();

	return 0;
}