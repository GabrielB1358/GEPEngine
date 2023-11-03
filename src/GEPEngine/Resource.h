#pragma once
#include <string>
#include <memory>


namespace GEPEngine
{
	struct Resource
	{
		virtual void onLoad();

		std::string getPath() const;

	private:
		friend class Resources;
		std::string m_path;

		void load();
	};
}