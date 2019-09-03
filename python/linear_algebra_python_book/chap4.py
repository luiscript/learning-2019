############# Chap 4 Introduction to NumPy Arrays


####### 4.2 NumPy N-dimensional Array

#create array

from numpy import array
l = [1.0, 2.0, 3.0]
a = array(l)

#print array
print(a)

#print array shape
print(a.shape)

#print array data type
print(a.dtype)


####### 4.3 Functions to Create Arrays

# 4.3.1 Empty
from numpy import empty
b = empty([3,3])
print(b)

# 4.3.2 Zeros
from numpy import zeros
c = zeros([3,5])
print(c)

# 4.3.3 Ones
from numpy import ones
d = ones([5])
print(d)


####### 4.4 Combining Arrays

# 4.4.1 Vertical Stack
from numpy import vstack
#first array
a1 = array([1,2,3])
#second array
a2 = array([4,5,6])
#vertical stack
a3 = vstack((a1, a2))
print(a3)
print(a3.shape)


# 4.4.2 Horizontal Stack
from numpy import hstack
b1 = array([1,2,3])
b2 = array([4,5,6])
b3 = hstack((b1, b2))
print(b3)
print(b3.shape)