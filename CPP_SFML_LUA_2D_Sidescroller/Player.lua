require("Entity")

Player = {}
Player.__index = Players

function Player:New(nr)

  local this = 
  {
    base = Entity:New(nr)
  }

  setmetatable(this, self)
  return this

end