#include <iostream>
//#include <GEPEngine/MyEngine.h>
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

	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<Curuthers> cat = entity->addComponent<Curuthers>();
	core->m_camera = entity->addComponent<Camera>();
	core->m_camera->setProj(false);
	//cat->m_renderer = entity->addComponent<GEPEngine::ModelRenderer>();
	//cat->m_collider = entity->addComponent<GEPEngine::BoxCollider>();
	//cat->m_rigibody = entity->addComponent<GEPEngine::Rigidbody>();


	std::shared_ptr<Entity> entity2 = core->addEntity();
	std::shared_ptr<evilBloke> naughty = entity2->addComponent<evilBloke>();

	//std::shared_ptr<ALSound> sound = entity->addComponent<ALSound>();

	//naughty->m_entity.lock()->getTransform()->Position = glm::vec3(2, 1, -10);
	cat->m_entity.lock()->getTransform()->Position = glm::vec3(-0.5, 0, -4);

	
	core->start();

	return 0;
}