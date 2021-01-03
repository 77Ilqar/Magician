#pragma once
#include "Application.h"

#ifdef MAGICIAN_PLATFORM_WINDOWS

extern Magician::Application* Magician::CreateApplication();

int main(int argc, char** argv)
{
	printf("Magician Engine");
	auto app = Magician::CreateApplication();
	app->Run();
	delete app;

}
#endif // MAGICIAN_PLATFORM_WINDOWS

