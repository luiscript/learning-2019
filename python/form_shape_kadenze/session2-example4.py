import rhinoscriptsyntax as rs 
import random

for c in range(100):
    listOfPoints = []
    for q in range(5):
        p1 = random.uniform(-100,100)
        p2 = random.uniform(-100,100)
        p3 = random.uniform(-100,100)
        listOfPoints.append([p1,p2,p3])
    rs.AddInterpCurve(listOfPoints,3)


