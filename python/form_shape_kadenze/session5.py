import rhinoscriptsyntax as rs
import random
import math

z = 0
radius = 30
pi = math.pi

while z <= 100:
  theta = 0
  while theta < 2 * pi:
    randomShift = random.uniform(-1,1) * (z/25.0)
    x = radius * math.cos(theta) + randomShift
    y = radius * math.sin(theta) + randomShift
    rs.AddPoint((x, y, z))
    theta += .05
  z += .3
