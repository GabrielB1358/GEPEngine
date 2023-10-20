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
	}

	GEPEngine::TriangleRenderer::~TriangleRenderer()
	{

	}

	void GEPEngine::TriangleRenderer::onInitialise()
	{

	}

	void GEPEngine::TriangleRenderer::onDisplay()
	{
		myShader->Render(vao, mytex);
		std::cout << "SDGFHSFGHSF" << std::endl;
	}
}
