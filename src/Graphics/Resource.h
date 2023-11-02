#pragma once
#include <string>



struct Resource
{
	virtual void onLoad() = 0;

	std::string getPath() const;

private:
	friend class Resource;
	std::string m_path;

	void load();
};