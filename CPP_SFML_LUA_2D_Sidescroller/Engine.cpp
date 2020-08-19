#include "pch.h"
#include "Engine.h"

void Engine::initStates()
{
	this->pushState("Game_State_Lua.lua");
}

void Engine::registerCppFunctions(lua_State* L)
{
	lua_pushcfunction(L, cpp_createWindow);
	lua_setglobal(L, "cpp_createWindow");
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

	this->states.top()->initialize();
}

void Engine::pollEvent()
{
	sf::Event e;
	while (this->window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			this->window.close();
			exit(0);
		}
	}
}

void Engine::update()
{
	this->pollEvent();

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
int Engine::cpp_createWindow(lua_State* L)
{
	lua_getglobal(L, LUA_ENGINE_ACCESSOR);
	Engine* engine = static_cast<Engine*>(lua_touserdata(L, -1));
	
	//std::cout << lua_gettop(L) << " ";
	//std::cout << lua_typename(L, lua_type(L, 1)) << " ";
	//std::cout << lua_typename(L, lua_type(L, 2)) << " ";
	//std::cout << lua_typename(L, lua_type(L, 3)) << " ";
	//std::cout << lua_typename(L, lua_type(L, 4)) << " ";
	//std::cout << lua_typename(L, lua_type(L, 5)) << " ";

	const unsigned vm_x = lua_tointeger(L, 1);
	const unsigned vm_y = lua_tointeger(L, 2);
	const std::string title = lua_tostring(L, 3);
	const bool fullscreen = lua_toboolean(L, 4);

	if(fullscreen)
		engine->window.create(sf::VideoMode(vm_x, vm_y), title, sf::Style::Fullscreen);
	else
		engine->window.create(sf::VideoMode(vm_x, vm_y), title, sf::Style::Close | sf::Style::Titlebar);

	return 0;
}
