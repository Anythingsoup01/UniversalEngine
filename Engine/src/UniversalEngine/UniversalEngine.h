#pragma once

namespace UniversalEngine {
	
	class Engine
	{
	public:
		Engine();

		~Engine();

		void Run();

		bool m_Running = true;
	};

	Engine* InitilizeEngine();

}