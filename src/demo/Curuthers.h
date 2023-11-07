#include <GEPEngine/Core.h>
#include <GEPEngine/Component.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/TriangleRenderer.h>


struct Curuthers : GEPEngine::Component
{
	void initialise();

	float angle;

private:
	std::shared_ptr<GEPEngine::TriangleRenderer> m_renderer;

	void onTick() override;
};