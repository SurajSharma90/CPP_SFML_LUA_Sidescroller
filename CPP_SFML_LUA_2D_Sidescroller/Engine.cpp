#include "pch.h"
#include "Engine.h"

void Engine::initStates()
{
	this->states.push(new State("Game_State_Lua.lua"));
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
	this->update();
	this->render();
}
