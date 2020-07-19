#pragma once

class State
{
private:
	lua_State* L;

public:
	State(const char* lua_state_file);
	~State();

	void update();
	void render();
};

