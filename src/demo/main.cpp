#include <iostream>
#include "Curuthers.h"
#include "evilBloke.h"
#include "billboard.h"
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
	std::shared_ptr<Entity> Billboard = core->addEntity();

	core->setCamera(camEntity->addComponent<Camera>());
	core->getCamera()->setOffset(glm::vec3(0, 1.1, 0));
	core->setPointLight(pointLight->addComponent<Light>());

	std::shared_ptr<Curuthers> cat = CuruthersEntity->addComponent<Curuthers>();
	std::shared_ptr<evilBloke> naughty = enemyEntity->addComponent<evilBloke>();
	std::shared_ptr<billboard> board = Billboard->addComponent<billboard>();

	std::shared_ptr<BoxCollider> catBox = CuruthersEntity->addComponent<BoxCollider>();
	std::shared_ptr<Rigidbody> catRigid = CuruthersEntity->addComponent<Rigidbody>();
	catBox->setSize(glm::vec3(0.4f, 0.4f, 0.4f));
	catBox->setOffset(glm::vec3(0));

	std::shared_ptr<BoxCollider> enemyBox = enemyEntity->addComponent<BoxCollider>();
	std::shared_ptr<Rigidbody> enemyRig = enemyEntity->addComponent<Rigidbody>();
	enemyBox->setSize(glm::vec3(0.4f, 2.0f, 0.4f));
	enemyBox->setOffset(glm::vec3(0));


	CuruthersEntity->SetPosition(glm::vec3(-1.0, 0, -10));
	enemyEntity->Move(glm::vec3(1.0, 0, -10));
	camEntity->SetPosition(glm::vec3(-0.5f, 0, -4));
	pointLight->SetPosition(glm::vec3(3.0f, 0, -5));
	Billboard->SetPosition(glm::vec3(3.0f, 0, -6));
	
	core->start();

	return 0;
}