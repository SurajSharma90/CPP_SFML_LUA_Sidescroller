require("Player")

print("GAME STATE START")

player = Player:New(2)

function Initialize()
	cpp_createWindow(1920, 1080, "MY WINDOW", false)
	cpp_setWindowFramerateLimit(144)
end

function Update()

end

function Render()
	cpp_clearWindow(0, 0, 0, 255)

	cpp_displayWindow()
end