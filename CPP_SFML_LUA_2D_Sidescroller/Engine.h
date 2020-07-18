#pragma once
class Engine
{
private:
	lua_State* L;

	void initLuaState();
	void initStates();

public:
	//Constructors & Destructors
	Engine();
	~Engine();

	//Accessors

	//Modifiers

	//Functions
	void update();
	void render();
	void run();
};

