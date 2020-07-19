#include "pch.h"
#include "Engine.h"
int main()
{
	Engine engine;
	try
	{
		engine.run();
	}
	catch (const char* e)
	{
		std::cout << "STRING::" << e << "\n";
	}
	catch (std::exception e)
	{
		std::cout << "EXCEPTION::" << e.what() << "\n";
	}

	return 0;
}