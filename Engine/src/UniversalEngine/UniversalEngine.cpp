#include "uepch.h"
#include "UniversalEngine.h"

namespace UniversalEngine {
	Engine::Engine()
	{
		std::cout << "Hello World!" << std::endl;

		//API_INFO("Engine Initilized!");
	}
	Engine::~Engine()
	{

	}
	void Engine::Run()
	{
		while (m_Running);
	}
}