#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Floor.h"
#include "billboard.h"
#include "GameLoop.h"
#include <GEPEngine/Camera.h>

#undef main


using namespace GEPEngine;

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> gameLoop = core->addEntity();
	gameLoop->addComponent<GameLoop>();

	core->start();

	/*
	std::shared_ptr<Core> core = Core::initialize();
	

	std::shared_ptr<Entity> groundEnt = core->addEntity();
	std::shared_ptr<Floor> floor = groundEnt->addComponent<Floor>();
	floor->m_floorCollider = groundEnt->addComponent<BoxCollider>();
	floor->m_floorCollider->setSize(glm::vec3(20, 1.0, 20));
	groundEnt->SetPosition(glm::vec3(0, -2, -10));
	groundEnt->getTransform()->setScale(glm::vec3(0.02, 0.02, 0.02));
	groundEnt->getTransform()->setRotation(glm::vec3(-90.0f, 0.0f, 0));

	///////////////////
	std::shared_ptr<Entity> PlayerEnt = core->addEntity();
	std::shared_ptr<Entity> enemyEntity = core->addEntity();
	std::shared_ptr<Entity> camEntity = core->addEntity();
	std::shared_ptr<Entity> pointLight = core->addEntity();
	std::shared_ptr<Entity> Billboard = core->addEntity();

	core->setCamera(camEntity->addComponent<Camera>());
	core->getCamera()->setOffset(glm::vec3(0, 1.1, 0));
	core->setPointLight(pointLight->addComponent<Light>());

	std::shared_ptr<Player> cat = PlayerEnt->addComponent<Player>();
	std::shared_ptr<Enemy> naughty = enemyEntity->addComponent<Enemy>();
	std::shared_ptr<billboard> board = Billboard->addComponent<billboard>();

	std::shared_ptr<BoxCollider> catBox = PlayerEnt->addComponent<BoxCollider>();
	std::shared_ptr<Rigidbody> catRigid = PlayerEnt->addComponent<Rigidbody>();
	catBox->setSize(glm::vec3(0.4f, 0.4f, 0.4f));
	catBox->setOffset(glm::vec3(0));

	std::shared_ptr<BoxCollider> enemyBox = enemyEntity->addComponent<BoxCollider>();
	std::shared_ptr<Rigidbody> enemyRig = enemyEntity->addComponent<Rigidbody>();
	enemyBox->setSize(glm::vec3(0.4f, 2.0f, 0.4f));
	enemyBox->setOffset(glm::vec3(0));


	PlayerEnt->SetPosition(glm::vec3(-2.5, 0, -10));
	enemyEntity->Move(glm::vec3(1.0, 0, -10));
	camEntity->SetPosition(glm::vec3(0.0f, 0, -4));
	pointLight->SetPosition(glm::vec3(3.0f, 0, -5));
	Billboard->SetPosition(glm::vec3(3.0f, 0, -6));
	*/
	////////////////////
	
	core->start();
	
	return 0;
}