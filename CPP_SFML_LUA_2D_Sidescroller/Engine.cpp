#include "pch.h"
#include "Engine.h"

void Engine::initStates()
{
	this->test = 400;
	this->pushState("Game_State_Lua.lua");
}

void Engine::registerCppFunctions(lua_State* L)
{
	lua_pushcfunction(L, luaTest);
	lua_setglobal(L, "cpp_luaTest");
}

Engine::Engine()
{
	this->initStates();
}

Engine::~Engine()
{
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Engine::pushState(const char* lua_state_file)
{
	this->states.push(new State("Game_State_Lua.lua"));

	lua_pushlightuserdata(this->states.top()->getLuaState(), this);
	lua_setglobal(this->states.top()->getLuaState(), LUA_ENGINE_ACCESSOR);

	this->registerCppFunctions(this->states.top()->getLuaState());

	this->states.top()->loadFile();
}

void Engine::update()
{
	this->states.top()->update();
}

void Engine::render()
{
	this->states.top()->render();
}

void Engine::run()
{
	//Main game loop
	while(!this->states.empty())
	{ 
		this->update();
		this->render();
	}
}

//LUA Static Functions
int Engine::luaTest(lua_State* L)
{
	lua_getglobal(L, LUA_ENGINE_ACCESSOR);
	Engine* engine = static_cast<Engine*>(lua_touserdata(L, -1));

	std::cout << "Hello from C++!" << engine->test << "\n";

	return 0;
}
