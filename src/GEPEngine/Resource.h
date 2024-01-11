#pragma once
#include <string>
#include <memory>


namespace GEPEngine
{
	struct Resource
	{
		virtual void onLoad();
		void load();

		std::string getPath() const;
		float getLifeTime();

		void setLifeTime(double _lt);

	private:
		friend class Resources;

		std::string m_path;

		float lifeTime;
	};
}