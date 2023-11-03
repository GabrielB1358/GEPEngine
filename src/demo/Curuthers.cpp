#include "Curuthers.h"
#include <GEPEngine/myEngine.h>


void Curuthers::initialise()
{
	//_modelMatrix = m_entity.lock()->getT
	//_projectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	//m_Texture = getCore()->getResources()->load<GEPEngine::Texture>("../Models/curuthers/Whiskers_diffuse");
	//m_Model = getCore()->getResources()->load<GEPEngine::Model>("../Modes/curuthers/curuthers.obj");
	//m_Shader = getCore()->getResources()->load<GEPEngine::Shader>("../Shaders/gui");

	//m_entity.lock()->addComponent<GEPEngine::TriangleRenderer>();

	m_renderer = m_entity.lock()->addComponent<GEPEngine::TriangleRenderer>();

	std::shared_ptr<GEPEngine::Model> m = getCore()->getResources()->load<GEPEngine::Model>("../Models/curuthers/curuthers.obj");
	std::shared_ptr<GEPEngine::Texture> t = getCore()->getResources()->load<GEPEngine::Texture>("../Models/curuthers/Whiskers_diffuse.png");

	m_renderer->setModel(m);
	m_renderer->setTexture(t);

	m_renderer->assembleShader();
	
	angle = 0;
}

void Curuthers::onTick()
{
	angle = 180 * getCore()->m_environment->getDT();
	m_entity.lock()->getTransform()->Rotation.y += angle;
}

void Curuthers::onDisplay()
{
	m_renderer->Render();
}