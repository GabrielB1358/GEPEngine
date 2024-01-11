#include "ModelRenderer.h"
#include "Entity.h"
#include "Core.h"
#include <Graphics/Rend.h>

namespace GEPEngine
{
	ModelRenderer::ModelRenderer()
	{


		//VBO stuff here for reference for when making orthographic renderer and that x
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

		m_vao = std::make_shared <Graphics::Vao> ();

		m_vao->AddVbo(pos);
		m_vao->AddVbo(coords);

	}

	void ModelRenderer::onInitialise()
	{
	}

	void ModelRenderer::onTick()
	{
	}

	void ModelRenderer::onDisplay()
	{
		//Load the model, texture and shader resources
		m_Model = getCore()->getResources()->load<GEPEngine::Model>(m_modPath);
		m_Texture = getCore()->getResources()->load<GEPEngine::Texture>(m_texPath);
		m_Shader = getCore()->getResources()->load<GEPEngine::Shader>(m_shaderPath);
		m_Camera = getCore()->getCamera();
		
		//Use the shader Render function to display
		glm::mat4 modelMatrix = getEntity()->getTransform()->getModel();
		m_Shader->getShader()->Render(m_Model->getModel(), m_Texture->getTexture(), m_Camera, modelMatrix, getCore()->getLightPos());
	}

	void ModelRenderer::setFragPath(std::string _path) { m_fragPath = _path; }
	void ModelRenderer::setVertPath(std::string _path) { m_vertPath = _path; }
	std::string ModelRenderer::getFragPath() { return m_fragPath; }
	std::string ModelRenderer::getVertPath() { return m_vertPath; }
	
	void ModelRenderer::setModel(std::string _p)
	{
		m_modPath = _p;
	}

	void ModelRenderer::setTexture(std::string _p)
	{
		m_texPath = _p;
	}

	void ModelRenderer::setShader(std::string _p)
	{
		m_shaderPath = _p;
	}
}
