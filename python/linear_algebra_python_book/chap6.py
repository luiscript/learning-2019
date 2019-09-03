from numpy import array

#  6.4.1 Scalar and One-Dimensional Array

a = array([1,2,3])
b = 2
#  broadcast
c = a + b
#print(c)


#  6.4.2 Scalar and Two-Dimensional Array
A = array([
  [1,2,3],
  [1,2,3]
])
b = 2
C = A + b
#print(C)


#  6.4.3 One-Dimensional and Two-Dimensional Arrays
A = array([
  [1,2,3],
  [1,2,3]
])
b = array([1,2,3])
C = A + b
#print(C)


# Arithmetic, including broadcasting, can only be
# performed when the shape of each dimension in the 
# arrays are equal or one has the dimension size of 1


A = array([
  [1,2,3],
  [1,2,3]
])
b = array([1,2])
C = A + b
print(C)