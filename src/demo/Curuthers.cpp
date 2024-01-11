#include "Curuthers.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>
#include <GEPEngine/GUI.h>


Curuthers::Curuthers()
{

}

Curuthers::Curuthers(bool greg)
{
	
}


void Curuthers::initialise()
{
	m_renderer = getEntity()->addComponent<GEPEngine::ModelRenderer>();
	m_collider = getEntity()->addComponent<GEPEngine::BoxCollider>();
	m_rigibody = getEntity()->addComponent<GEPEngine::Rigidbody>();

	m_renderer->setModel("../Models/curuthers/curuthers.obj");
	m_renderer->setTexture("../Models/curuthers/Whiskers_diffuse.png");
	m_renderer->setShader("../Shaders/notGUI");

	m_collider->setSize(glm::vec3(0.5f, 0.5f, 0.5f));
	m_collider->setOffset(glm::vec3(0));


	hornSound = getEntity()->addComponent<GEPEngine::ALAudio>("../dixie_horn.ogg");
	pigeonSound = getEntity()->addComponent<GEPEngine::ALAudio>("../PigeonCoo.ogg");


	angle = 0;
	Move(glm::vec3(0, -0.5, -8));
	Scale(glm::vec3(0.25, 0.25, 0.25));
}

void Curuthers::onTick()
{
	angle = 180 * getCore()->getDT();
	float step = getCore()->getDT() * 1;

	if (getInput()->isKey(GEPEngine::Keys::leftM) == true)
	{

	}
	if (getInput()->isKey(GEPEngine::Keys::d) == true)
	{
		Move(glm::vec3(step, 0, 0));
	}
	if (getInput()->isKey(GEPEngine::Keys::a) == true)
	{
		Move(glm::vec3(-step, 0, 0));
	}
	if (getInput()->isKey(GEPEngine::Keys::w) == true)
	{
		Move(glm::vec3(0, step, 0));
	}
	if (getInput()->isKey(GEPEngine::Keys::s) == true)
	{
		Move(glm::vec3(0, -step, 0));
	}
	if (getInput()->isKey(GEPEngine::Keys::space) == true)
	{
		Move(glm::vec3(0, 0, -step));
	}
	if (getInput()->isKey(GEPEngine::Keys::lshift) == true)
	{
		Move(glm::vec3(0, 0, step));
	}
}

void Curuthers::Move(glm::vec3 _move)
{
	getEntity()->getTransform()->Move(_move);
}

void Curuthers::Scale(glm::vec3 _scale)
{
	getEntity()->getTransform()->Scale = _scale;
}

void Curuthers::onGUI()
{
	if (getCore()->getGUI()->Button("../Textures/Buttons/DownButton.png", "../Textures/Buttons/UpButton.png", glm::vec2(800,800), glm::vec2(200, 150)))
	{
		hornSound->playSound();
	}
}
