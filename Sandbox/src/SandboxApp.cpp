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
	return new Sandbox();
}