#include "pch.h"
#include "Engine.h"

void Engine::initLuaState()
{
	this->L = luaL_newstate();

	luaL_openlibs(this->L);
}

void Engine::initStates()
{
	int error = luaL_dofile(this->L, "Game_State_Lua.lua");
}

Engine::Engine()
{
	this->initLuaState();
	this->initStates();
}

Engine::~Engine()
{
	lua_close(this->L);
}

void Engine::update()
{
}

void Engine::render()
{
}

void Engine::run()
{
	this->update();
	this->render();
}
