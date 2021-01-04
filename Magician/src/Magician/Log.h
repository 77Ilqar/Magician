#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Magician {
	class MAGICIAN_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define MAGICIAN_CORE_TRACE(...)	::Magician::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define MAGICIAN_CORE_INFO(...)	    ::Magician::Log::GetCoreLogger()->info(__VA_ARGS__);
#define MAGICIAN_CORE_WARN(...)	    ::Magician::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define MAGICIAN_CORE_ERROR(...)	::Magician::Log::GetCoreLogger()->error(__VA_ARGS__);
#define MAGICIAN_CORE_FATAL(...)	::Magician::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//Client log macros
#define MAGICIAN_TRACE(...)		 	::Magician::Log::GetClientLogger()->trace(__VA_ARGS__);
#define MAGICIAN_INFO(...)		    ::Magician::Log::GetClientLogger()->info(__VA_ARGS__);
#define MAGICIAN_WARN(...)		    ::Magician::Log::GetClientLogger()->warn(__VA_ARGS__);
#define MAGICIAN_ERROR(...)			::Magician::Log::GetClientLogger()->error(__VA_ARGS__);
#define MAGICIAN_FATAL(...)			::Magician::Log::GetClientLogger()->fatal(__VA_ARGS__);