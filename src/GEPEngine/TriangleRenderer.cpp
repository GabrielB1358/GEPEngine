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

	}

	void TriangleRenderer::onInitialise()
	{
	}

	void TriangleRenderer::onTick()
	{
	}

	void TriangleRenderer::onDisplay()
	{
		m_Model = getCore()->getResources()->load<GEPEngine::Model>(m_modPath);
		m_Texture = getCore()->getResources()->load<GEPEngine::Texture>(m_texPath);
		m_Shader = getCore()->getResources()->load<GEPEngine::Shader>(m_shaderPath);

		std::shared_ptr<Transform> tmp = m_entity.lock()->getTransform();
		m_Shader->getShader()->Render(m_Model->getModel(), m_Texture->getTexture(), tmp->getModel(), tmp->getProjection());
	}

	void TriangleRenderer::setFragPath(std::string _path) { m_fragPath = _path; }
	void TriangleRenderer::setVertPath(std::string _path) { m_vertPath = _path; }
	std::string TriangleRenderer::getFragPath() { return m_fragPath; }
	std::string TriangleRenderer::getVertPath() { return m_vertPath; }
	
	void TriangleRenderer::setModel(std::string _p)
	{
		m_modPath = _p;
	}

	void TriangleRenderer::setTexture(std::string _p)
	{
		m_texPath = _p;
	}

	void TriangleRenderer::setShader(std::string _p)
	{
		m_shaderPath = _p;
	}
}
