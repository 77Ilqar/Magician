#pragma once

#ifdef MAGICIAN_PLATFORM_WINDOWS
#ifdef MAGICIAN_BUILD_DLL
#define MAGICIAN_API __declspec(dllexport)
#else 
#define MAGICIAN_API __declspec(dllimport)
#endif // MAGICIAN_BUILD_DLL
#else 
#error Magician only supports Windows!

#endif // MAGICIAN_PLATFORM_WINDOWS

