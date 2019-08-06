import rhinoscriptsyntax as rs
import random
import math

z = 0
radius = 30
pi = math.pi

while z <= 100:
  theta = 0
  while theta < 2 * pi:
    x = radius * math.cos(theta)
    y = radius * math.sin(theta)
    rs.AddPoint((x, y, z))
    theta += .1
  z += .5
