require("Player")
print("HELLO FROM LUA!")

player = Player:New(2)

function Update()
	print("UPDATE!")
	print(player.base.myNum)
end

function Render()
	print("RENDER!")
end