#pragma once
#include "Core.h"


namespace Magician {
	class MAGICIAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
}
