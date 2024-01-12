#pragma once
#include <string>
#include <memory>


namespace GEPEngine
{
	struct Resource
	{
		//Resource is a parent class holding the lifetime and string path of any child resource variables

		virtual void onLoad();
		void load();

		std::string getPath() const;
		float getLifeTime();

		void setLifeTime(double _lt);

	private:
		friend class Resources;

		std::string m_path;

		float m_lifeTime;
	};
}