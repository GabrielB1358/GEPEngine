#include "Environment.h"
#include <Windows.h>


namespace GEPEngine
{
	void Environment::Init()
	{
#ifdef _WIN32
		m_last = GetTickCount();
#else
		struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		last = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif // !_WIN32

	}

	void Environment::Tick()
	{
#ifdef _WIN32
		DWORD curr = GetTickCount();
#else
		struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		double curr = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
		double diff = curr - m_last;
		m_deltaTime = diff / 1000.0f;
		m_last = curr;
	}

	double Environment::getDT()
	{
		return m_deltaTime;
	}
}
