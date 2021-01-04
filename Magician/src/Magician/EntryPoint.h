#pragma once
#include "Application.h"

#ifdef MAGICIAN_PLATFORM_WINDOWS

extern Magician::Application* Magician::CreateApplication();

int main(int argc, char** argv)
{
	Magician::Log::Init();
	MAGICIAN_CORE_ERROR("error");
	int a = 5;
	MAGICIAN_INFO("info {0}", a);


	printf("Entry Point");
	auto app = Magician::CreateApplication();
	app->Run();
	delete app;

}
#endif // MAGICIAN_PLATFORM_WINDOWS

