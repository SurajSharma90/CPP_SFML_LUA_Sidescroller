#include "pch.h"
#include "Engine.h"
int main()
{
	Engine engine;
	try
	{
		engine.run();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR: " << e.what() << "\n";
	}

	return 0;
}