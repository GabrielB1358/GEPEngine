#include "Curuthers.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Keyboard.h>


void Curuthers::initialise()
{
	m_renderer = m_entity.lock()->addComponent<GEPEngine::ModelRenderer>();
	m_collider = m_entity.lock()->addComponent<GEPEngine::BoxCollider>();
	m_rigibody = m_entity.lock()->addComponent<GEPEngine::Rigidbody>();

	m_renderer->setModel("../Models/curuthers/curuthers.obj");
	m_renderer->setTexture("../Models/curuthers/Whiskers_diffuse.png");
	m_renderer->setShader("../Shaders/gui");

	m_collider->m_size = glm::vec3(0.5f, 0.5f, 0.5f);
	m_collider->m_offset = glm::vec3(0);



	angle = 0;
	Move(glm::vec3(0, -0.5, -8));
	Scale(glm::vec3(0.25, 0.25, 0.25));
}

void Curuthers::onTick()
{
	angle = 180 * getCore()->m_environment->getDT();
	float step = getCore()->m_environment->getDT() * 1;
	//m_entity.lock()->getTransform()->Rotate(glm::vec3(0, angle, 0));
	
	if (getKeyboard()->isKey(GEPEngine::Keys::d) == true)
	{
		Move(glm::vec3(step, 0, 0));
		//m_soundSource->playSound("../dixie_horn.ogg");
	}
	if (getKeyboard()->isKey(GEPEngine::Keys::a) == true)
	{
		Move(glm::vec3(-step, 0, 0));
	}
	if (getKeyboard()->isKey(GEPEngine::Keys::w) == true)
	{
		Move(glm::vec3(0, step, 0));
	}
	if (getKeyboard()->isKey(GEPEngine::Keys::s) == true)
	{
		Move(glm::vec3(0, -step, 0));
	}
	if (getKeyboard()->isKey(GEPEngine::Keys::space) == true)
	{
		Move(glm::vec3(0, 0, -step));
	}
	if (getKeyboard()->isKey(GEPEngine::Keys::lshift) == true)
	{
		Move(glm::vec3(0, 0, step));
	}
}

void Curuthers::Move(glm::vec3 _move)
{
	m_entity.lock()->getTransform()->Move(_move);
}

void Curuthers::Scale(glm::vec3 _scale)
{
	m_entity.lock()->getTransform()->Scale = _scale;
}
