#pragma once
#include <string>
#include <memory>


namespace GEPEngine
{
	struct Resource
	{
		virtual void onLoad();

		std::string getPath() const;
		float getLifeTime();
		void setLifeTime(double _lt);

	private:
		friend class Resources;
		std::string m_path;

		float lifeTime;

		void load();
	};
}