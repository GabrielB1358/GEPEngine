#include <GEPEngine/Model.h>

namespace GEPEngine
{
	void Model::onLoad()
	{
		m_model = std::make_shared<Graphics::WavefrontMesh>(getPath().c_str());
	}
	std::shared_ptr<Graphics::WavefrontMesh> Model::getModel()
	{
		return m_model;
	}
}