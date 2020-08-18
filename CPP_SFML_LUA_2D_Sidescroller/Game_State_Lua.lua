require("Player")
print("HELLO FROM LUA!")

player = Player:New(2)

function Initialize()
	cpp_createWindow(1920, 1080, "Lua Game Engine", false)
end

function Update()
	
end

function Render()
	cpp_clearWindow(255, 0, 0, 255)



	cpp_displayWindow()
end