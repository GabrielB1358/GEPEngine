#include "TriangleRenderer.h"
#include <Graphics/Rend.h>

namespace GEPEngine
{
	TriangleRenderer::TriangleRenderer()
	{
		std::shared_ptr<Vbo> pos = std::make_shared<Vbo>();
		pos->Add(glm::vec3(-0.5f, 0.5f, 0.0f));
		pos->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, -0.5f, 0.0f));
		pos->Add(glm::vec3(0.5f, 0.5f, 0.0f));
		pos->Add(glm::vec3(-0.5f, 0.5f, 0.0f));

		std::shared_ptr<Vbo> coords = std::make_shared<Vbo>();
		coords->Add(glm::vec2(0.0f, 1.0f));
		coords->Add(glm::vec2(0.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 0.0f));
		coords->Add(glm::vec2(1.0f, 1.0f));
		coords->Add(glm::vec2(0.0f, 1.0f));

		vao = std::make_shared<Vao>();

		vao->AddVbo(pos);
		vao->AddVbo(coords);

		myShader = std::make_shared<Shader>("../Shaders/GUIFragment.txt", "../Shaders/GUIVertex.txt");

		mytex = std::make_shared<Texture>();

		rotation = 0.0f;
		_projectionMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 0.01f, 100.0f);
		_modelMatrix = glm::translate(glm::mat4(1), glm::vec3(0.0f, 0.0f, -10.0f));
	}

	GEPEngine::TriangleRenderer::~TriangleRenderer()
	{

	}

	void GEPEngine::TriangleRenderer::onInitialise()
	{

	}

	void GEPEngine::TriangleRenderer::onTick()
	{
		rotation += 0.5f;
		_modelMatrix = glm::rotate(_modelMatrix, glm::radians(rotation), glm::vec3(1.0f, 0.0f, 0.0f));
		myShader->BindShader("u_Projection", _projectionMatrix);
		myShader->BindShader("u_Model", _modelMatrix);
	}

	void GEPEngine::TriangleRenderer::onDisplay()
	{
		//call shader bind function, passing values from transform
		myShader->Render(vao, mytex, _modelMatrix, _projectionMatrix);
		std::cout << "SDGFHSFGHSF" << std::endl;
	}
}
