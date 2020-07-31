Entity = {}
Entity.__index = Entity

function Entity:New(nr)

  local this = 
  {
    myNum = nr
  }

  setmetatable(this, self)
  return this

end

function Entity:Print()
  print("Entity!")
end