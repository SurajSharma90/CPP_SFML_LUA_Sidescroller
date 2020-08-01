#pragma once

class State
{
private:
	lua_State* L;
	std::string lua_state_file;

public:
	State(const char* lua_state_file);
	~State();

	//Accessors
	inline lua_State* getLuaState() {return this->L;}

	//Functions
	void loadFile();

	void update();
	void render();
};

