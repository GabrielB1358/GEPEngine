#include "QuadRenderer.h"
#include "Core.h"

namespace GEPEngine
{

	void QuadRenderer::onDisplay()
	{
		//Prepare the VBOs and VAO
		std::shared_ptr<Graphics::Vbo> positions = std::make_shared<Graphics::Vbo>();
		std::shared_ptr<Graphics::Vbo> texCoords = std::make_shared<Graphics::Vbo>();
		m_vao = std::make_shared<Graphics::Vao>();

		positions->Add(glm::vec3(-0.5f, 0.5f, 0.0f));
		positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		positions->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		positions->Add(glm::vec3(0.5f, 0.5f, 0.0f));
		positions->Add(glm::vec3(-0.5f, 0.5f, 0.0f));

		texCoords->Add(glm::vec2(0.0f, 1.0f));
		texCoords->Add(glm::vec2(0.0f, 0.0f));
		texCoords->Add(glm::vec2(1.0f, 0.0f));
		texCoords->Add(glm::vec2(1.0f, 0.0f));
		texCoords->Add(glm::vec2(1.0f, 1.0f));
		texCoords->Add(glm::vec2(0.0f, 1.0f));

		m_vao->AddVbo(positions);
		m_vao->AddVbo(texCoords);

		//Prepare the Texture, Shader and Camera
		m_tex = getCore()->getResources()->load<GEPEngine::Texture>(m_texPath);
		m_shader = getCore()->getResources()->load<GEPEngine::Shader>(m_shadPath);
		m_camera = getCore()->getCamera();

		//Create model matrix and tell shader to render
		glm::mat4 modelMatrix = getEntity()->getTransform()->getModel();
		m_shader->getShader()->RenderPerspQuad(m_vao, m_tex->getTexture(), m_camera, modelMatrix, getCore()->getLightPos());
	}

	void QuadRenderer::setTexture(std::string _p)
	{
		m_texPath = _p;
	}

	void QuadRenderer::setShader(std::string _p)
	{
		m_shadPath = _p;
	}

	void QuadRenderer::setVao(std::shared_ptr<Graphics::Vao> _vao)
	{
		m_vao = _vao;
	}
}