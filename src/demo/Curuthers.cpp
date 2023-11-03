#include "Curuthers.h"
#include <GEPEngine/myEngine.h>


void Curuthers::initialise()
{
	//_modelMatrix = m_entity.lock()->getT
	//_projectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	//m_Texture = getCore()->getResources()->load<GEPEngine::Texture>("../Models/curuthers/Whiskers_diffuse");
	//m_Model = getCore()->getResources()->load<GEPEngine::Model>("../Modes/curuthers/curuthers.obj");
	//m_Shader = getCore()->getResources()->load<GEPEngine::Shader>("../Shaders/gui");

	m_entity.lock()->addComponent<GEPEngine::TriangleRenderer>();



	// ADD A MODEL RENDERER CLASS THEN UNCOMMENT
	//std::shared_ptr<GEPEngine::ModelRenderer> mr =  m_entity.lock()->addComponent<GEPEngine::ModelRenderer>();

	//std::shared_ptr<GEPEngine::Model> m = getCore()->getResources()->load<GEPEngine::Model>("../Modes/curuthers/curuthers.obj");
	//mr->setModel(m);
}