import rhinoscriptsyntax as rs 
import random

random.seed(1)
myVal = random.uniform(1,10)
print (myVal)

random.seed(1)
myVal = random.uniform(1,10)
print (myVal)


myVal = random.randint(1,10)
print(myVal)

myVal = random.triangular(1,10,2)
print(myVal)
