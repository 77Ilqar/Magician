#include <Magician.h>


class Sandbox :public Magician::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Magician::Application* Magician::CreateApplication()
{
	printf("SandboxApp");
	return new Sandbox();
}