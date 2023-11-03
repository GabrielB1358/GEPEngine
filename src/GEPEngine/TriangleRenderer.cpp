#include "TriangleRenderer.h"
#include "Entity.h"
#include "Core.h"
#include <Graphics/Rend.h>

namespace GEPEngine
{
	TriangleRenderer::TriangleRenderer()
	{
		angle = 0;

		std::shared_ptr<Graphics::Vbo> pos = std::make_shared<Graphics::Vbo>();
		pos->Add(glm::vec3(-0.5f, 0.5f, 0.0f));
		pos->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, 0.5f, 0.0f));
		pos->Add(glm::vec3(-0.5f, 0.5f, 0.0f));

		std::shared_ptr<Graphics::Vbo> coords = std::make_shared<Graphics::Vbo>();
		coords->Add(glm::vec2(0.0f, 1.0f));
		coords->Add(glm::vec2(0.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 1.0f));
		coords->Add(glm::vec2(0.0f, 1.0f));

		vao = std::make_shared <Graphics::Vao> ();

		vao->AddVbo(pos);
		vao->AddVbo(coords);

		myShader = std::make_shared<Graphics::Shader>("../Shaders/GUIFragment.txt", "../Shaders/GUIVertex.txt");

		mytex = std::make_shared<Graphics::Texture>("../image.png");

		
	}

	void TriangleRenderer::onInitialise()
	{
		//m_entity.lock()->m_Transform->Move(glm::vec3(0, -0.5, -10));
	}

	void TriangleRenderer::onTick()
	{
		//std::shared_ptr<Entity> rtn = m_entity.lock();

		//angle = 180 * rtn->m_core.lock()->m_environment->getDT();
		//rtn->m_Transform->Rotation.y += angle;

	}

	void TriangleRenderer::onDisplay()
	{
		std::shared_ptr<Entity> rtn = m_entity.lock();
		//glm::mat4 tempMM = rtn->m_Transform->getModel();
		//glm::mat4 tempPM = rtn->m_Transform->getProjection();
		//myShader->Render(vao, mytex, tempMM, tempPM);
	}

	void TriangleRenderer::assembleShader()
	{
		//CHANGE THIS SO THAT PATH PARAMETER IS THE LOCAL STRINGS INSTEAD
		m_Shader = getCore()->getResources()->load<GEPEngine::Shader>("../Shaders/gui");
	}

	void TriangleRenderer::Render()
	{
		std::shared_ptr<Transform> tmp = m_entity.lock()->getTransform();
		m_Shader->getShader()->Render(m_Model->getModel() , m_Texture->getTexture(), tmp->getModel(), tmp->getProjection());
	}

	void TriangleRenderer::setFragPath(std::string _path) { m_fragPath = _path; }
	void TriangleRenderer::setVertPath(std::string _path) { m_vertPath = _path; }
	std::string TriangleRenderer::getFragPath() { return m_fragPath; }
	std::string TriangleRenderer::getVertPath() { return m_vertPath; }
	
	void TriangleRenderer::setModel(std::shared_ptr<GEPEngine::Model> _model)
	{
		m_Model = _model;
	}

	void TriangleRenderer::setTexture(std::shared_ptr<GEPEngine::Texture> _texture)
	{
		m_Texture = _texture;
	}
}
