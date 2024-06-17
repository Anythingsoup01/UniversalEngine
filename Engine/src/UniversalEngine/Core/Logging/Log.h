#pragma once
#include "spdlog/spdlog.h"

namespace UniversalEngine {
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetAPILogger() { return s_APILogger; }
		static std::shared_ptr<spdlog::logger>& GetCLILogger() { return s_CLILogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_APILogger;
		static std::shared_ptr<spdlog::logger> s_CLILogger;
	};

#if UE_DEBUG
// API Log Macros
#define API_CRITICAL(...)              ::UniversalEngine::Log::GetAPILogger()->critical(__VA_ARGS__)
#define API_ERROR(...)                 ::UniversalEngine::Log::GetAPILogger()->error(__VA_ARGS__)
#define API_WARN(...)                  ::UniversalEngine::Log::GetAPILogger()->warn(__VA_ARGS__)
#define API_INFO(...)                  ::UniversalEngine::Log::GetAPILogger()->info(__VA_ARGS__)
#define API_TRACE(...)                 ::UniversalEngine::Log::GetAPILogger()->trace(__VA_ARGS__)
#define API_ASSERT(x, ...) if (!(x)) { ::UniversalEngine::Log::GetAPILogger()->critical(__VA_ARGS__); __debugbreak(); }
// CLI Log Macros
#define CLI_CRITICAL(...)              ::UniversalEngine::Log::GetCLILogger()->critical(__VA_ARGS__)
#define CLI_ERROR(...)                 ::UniversalEngine::Log::GetCLILogger()->error(__VA_ARGS__)
#define CLI_WARN(...)                  ::UniversalEngine::Log::GetCLILogger()->warn(__VA_ARGS__)
#define CLI_INFO(...)                  ::UniversalEngine::Log::GetCLILogger()->info(__VA_ARGS__)
#define CLI_TRACE(...)                 ::UniversalEngine::Log::GetCLILogger()->trace(__VA_ARGS__)
#define CLI_ASSERT(x, ...) if (!(x)) { ::UniversalEngine::Log::GetCLILogger()->critical(__VA_ARGS__); __debugbreak(); }

#elif UE_RELEASE
// API Log Macros
#define API_CRITICAL(...) 
#define API_ERROR(...)    
#define API_WARN(...)     
#define API_INFO(...)     
#define API_TRACE(...)    
#define API_ASSERT(x, ...)
// CLI Log Macros
#define CLI_CRITICAL(...)              ::UniversalEngine::Log::GetCLILogger()->critical(__VA_ARGS__)
#define CLI_ERROR(...)                 ::UniversalEngine::Log::GetCLILogger()->error(__VA_ARGS__)
#define CLI_WARN(...)                  ::UniversalEngine::Log::GetCLILogger()->warn(__VA_ARGS__)
#define CLI_INFO(...)                  ::UniversalEngine::Log::GetCLILogger()->info(__VA_ARGS__)
#define CLI_TRACE(...)                 ::UniversalEngine::Log::GetCLILogger()->trace(__VA_ARGS__)
#define CLI_ASSERT(x, ...) if (!(x)) { ::UniversalEngine::Log::GetCLILogger()->critical(__VA_ARGS__); __debugbreak(); }
#endif

}