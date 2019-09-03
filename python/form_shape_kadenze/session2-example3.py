import rhinoscriptsyntax as rs 
import random 

c = 0
while c < 100:
    v1 = random.uniform(-100,100)
    v2 = random.uniform(-100,100)
    v3 = random.uniform(-100,100)
    v4 = random.uniform(-100,100)
    v5 = random.uniform(-100,100)
    v6 = random.uniform(-100,100)
    v7 = random.uniform(-100,100)
    v8 = random.uniform(-100,100)
    v9 = random.uniform(-100,100)

    p1 = [v1,v2,v3]
    p2 = [v4,v5,v6]
    p3 = [v7,v8,v9]

    rs.AddInterpCurve([p1,p2,p3], 3)

    c+=1

    