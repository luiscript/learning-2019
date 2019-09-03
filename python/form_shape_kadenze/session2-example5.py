import rhinoscriptsyntax as rs 
import random

def randoCurve(nPoints):
    listOfPoints = []
    for q in range(nPoints):
        p1 = random.uniform(-100,100)
        p2 = random.uniform(-100,100)
        p3 = random.uniform(-100,100)
        listOfPoints.append([p1,p2,p3])
    rs.AddInterpCurve(listOfPoints, 3)

#randoCurve(1000)

for c in range(10):
    randoCurve(c+2)