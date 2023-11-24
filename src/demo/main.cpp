#include <iostream>
#include <GEPEngine/MyEngine.h>
#include "Curuthers.h"
#include "evilBloke.h"

#undef main


using namespace GEPEngine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<Curuthers> cat = entity->addComponent<Curuthers>();

	std::shared_ptr<Entity> entity2 = core->addEntity();
	std::shared_ptr<evilBloke> naughty = entity2->addComponent<evilBloke>();

	//naughty->m_entity.lock()->getTransform()->Position = glm::vec3(2, 1, -10);
	cat->m_entity.lock()->getTransform()->Position = glm::vec3(-0.5, 0, -4);
	core->start();

	return 0;
}