#include "ModelRenderer.h"
#include "Entity.h"
#include "Core.h"
#include <Graphics/Rend.h>

namespace GEPEngine
{
	ModelRenderer::ModelRenderer()
	{
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
		
		//Tell shader to render
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
