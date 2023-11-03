#include <GEPEngine/Core.h>
#include <GEPEngine/Component.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/TriangleRenderer.h>


struct Curuthers : GEPEngine::Component
{
	void initialise();

	//glm::mat4 _modelMatrix;
	//glm::mat4 _projectionMatrix;
	float angle;

private:
	std::shared_ptr<GEPEngine::TriangleRenderer> m_renderer;

	void onDisplay() override;
	void onTick() override;
	//std::shared_ptr<GEPEngine::Texture> m_Texture;
	//std::shared_ptr<GEPEngine::Model> m_Model;
	//std::shared_ptr<GEPEngine::Shader> m_Shader;
};