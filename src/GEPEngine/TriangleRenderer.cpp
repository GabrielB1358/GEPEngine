#include "TriangleRenderer.h"
#include "Entity.h"
#include "Core.h"
#include <Graphics/Rend.h>

namespace GEPEngine
{
	TriangleRenderer::TriangleRenderer()
	{
		angle = 0;

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

	TriangleRenderer::~TriangleRenderer()
	{

	}

	void TriangleRenderer::onInitialise()
	{
		m_entity.lock()->m_Transform->Move(glm::vec3(0, -0.5, -10));
	}

	void TriangleRenderer::onTick()
	{
		std::shared_ptr<Entity> rtn = m_entity.lock();

		angle = 180 * rtn->m_core.lock()->m_environment->getDT();
		rtn->m_Transform->Rotation.y += angle;

	}

	void TriangleRenderer::onDisplay()
	{
		std::shared_ptr<Entity> rtn = m_entity.lock();
		glm::mat4 tempMM = rtn->m_Transform->getModel();
		glm::mat4 tempPM = rtn->m_Transform->getProjection();
		myShader->Render(vao, mytex, tempMM, tempPM);
	}
}
