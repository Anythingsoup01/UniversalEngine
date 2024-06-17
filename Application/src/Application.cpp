#include "Engine.h"

class Application : public UniversalEngine::Engine {
public:
	Application() {
		//CLI_TRACE("Client Initialized!");
	}

	~Application() {

	}
};

UniversalEngine::Engine* UniversalEngine::InitilizeEngine() {
	return new Application();
}