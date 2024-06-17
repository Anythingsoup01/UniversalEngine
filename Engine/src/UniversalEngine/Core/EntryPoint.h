#pragma once

#ifdef UE_PLATFORM_WINDOWS

extern UniversalEngine::Engine* UniversalEngine::InitilizeEngine();

int main(int argc, char* argv[])
{
	UniversalEngine::Log::Init();

	auto app = UniversalEngine::InitilizeEngine();
	app->Run();
	delete(app);
}

#endif // UE_PLATFORM_WINDOWS
