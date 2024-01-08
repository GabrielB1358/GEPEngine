#include <iostream>
#include "Curuthers.h"
#include "evilBloke.h"
#include <GEPEngine/Camera.h>

#undef main


using namespace GEPEngine;

int main()
{
	//Supposedly make it so that every entity has their components added like this
	//^^ no adding components within the class, eg. curuthers.cpp

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> CuruthersEntity = core->addEntity();
	core->m_camera = CuruthersEntity->addComponent<Camera>();
	core->m_camera->setProj(false);
	std::shared_ptr<Curuthers> cat = CuruthersEntity->addComponent<Curuthers>();

	std::shared_ptr<Entity> entity2 = core->addEntity();
	std::shared_ptr<evilBloke> naughty = entity2->addComponent<evilBloke>();
	core->m_pointLight = entity2->addComponent<Light>();

	cat->m_entity.lock()->getTransform()->Position = glm::vec3(-0.5, 0, -4);

	
	core->start();

	return 0;
}