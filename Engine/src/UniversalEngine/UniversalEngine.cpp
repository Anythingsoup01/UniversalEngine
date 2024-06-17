#include "uepch.h"
#include "UniversalEngine.h"

namespace UniversalEngine {
	Engine::Engine()
	{
		API_INFO("Engine Initilized!");
	}
	Engine::~Engine()
	{

	}
	void Engine::Run()
	{
		while (m_Running);
	}
}