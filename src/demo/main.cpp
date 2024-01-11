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
	std::shared_ptr<Entity> enemyEntity = core->addEntity();
	std::shared_ptr<Entity> camEntity = core->addEntity();
	std::shared_ptr<Entity> pointLight = core->addEntity();

	core->setCamera(camEntity->addComponent<Camera>());
	core->setPointLight(pointLight->addComponent<Light>());

	std::shared_ptr<Curuthers> cat = CuruthersEntity->addComponent<Curuthers>();
	std::shared_ptr<evilBloke> naughty = enemyEntity->addComponent<evilBloke>();

	cat->getEntity()->getTransform()->setPosition(glm::vec3(-0.5, 0, -8));

	enemyEntity->Move(glm::vec3(0, 0, -10));
	camEntity->SetPosition(glm::vec3(-0.5f, 0, -4));
	pointLight->SetPosition(glm::vec3(1.0f, 0, -6));

	
	core->start();

	return 0;
}