#include "pch.h"
#include "State.h"

State::State(const char* lua_state_file)
{
	//Init lua state
	this->L = luaL_newstate();
	luaL_openlibs(this->L);

	this->lua_state_file = lua_state_file;
}

State::~State()
{
	lua_close(this->L);
}

void State::loadFile()
{
	int error = luaL_dofile(this->L, this->lua_state_file.c_str());
	if (error)
	{
		std::cout << "LUA::ERROR::STATE::CONSTRUCTOR::" << lua_tostring(this->L, -1) << "\n";
		lua_pop(this->L, lua_gettop(this->L));
		throw("CPP::ERROR::STATE::CONSTRUCTOR::Could not open file %s", lua_state_file.c_str());
	}
}

void State::update()
{
	lua_getglobal(this->L, "Update");
	int error = lua_pcall(this->L, 0, 0, 0);
	if (error)
	{
		std::cout << "LUA::ERROR::STATE::UPDATE::" << lua_tostring(this->L, -1) << "\n";
		lua_pop(this->L, lua_gettop(this->L));
		throw("CPP::ERROR::STATE::UPDATE::Cannot call Update function.");
	}
}

void State::render()
{
	lua_getglobal(this->L, "Render");
	int error = lua_pcall(this->L, 0, 0, 0);
	if (error)
	{
		std::cout << "LUA::ERROR::STATE::RENDER::" << lua_tostring(this->L, -1) << "\n";
		lua_pop(this->L, lua_gettop(this->L));
		throw("CPP::ERROR::STATE::UPDATE::Cannot call Render function.");
	}
}
