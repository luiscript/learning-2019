############## Chap 5 Index, Slice and Reshape NumPy Arrays


####### 5.2.1 One-Dimensional List to Array
#create one-dimensional array
from numpy import array
data = [11,22,33,44,55]
data = array(data)
print(data)
print(type(data))


####### 5.2.2 Two-Dimensional List to Array
#create two-dimensional array
data = [[11,22], [33,44], [55,66]]
data = array(data)
print(data)
print(type(data))


####### 5.3.1 One-dimensional indexing
data = array([11, 22, 33, 44, 55])
print(data[0])
print(data[4])
# -1 index refers to last item (55) -2 refers to (44)
print(data[-1])
print(data[-5])


####### 5.3.2 Two-dimensional indexing
data = array([
  [11,22], 
  [33,44], 
  [55,66]])
print(data[0,0])
print(data[1])


########## 5.4 Array Slicing

####### 5.4.1 One-dimensional Slicing
data = array([11,22,33,44,55])
#returns a sub array with [beginIndex : endIndex]
print(data[0:1])
print(data[-2:])

####### 5.4.2 Two-Dimensional Slicing
data = array([
  [11,22,33],
  [44,55,66],
  [77,88,99]
])
x, y = data[:, :-1], data[:,-1]
print(x)
print(y)


split = 2
train = data[:split, :]
test = data[split:, :]

print(train)
print(test)


############ 5.5 Array reshaping


####### 5.5.1 Data shape

data = array([11,22,33,44,55])
print(data.shape)

data = [
  [11, 22],
  [33,44], 
  [55,66]
]
data = array(data)
print('Rows %d' %data.shape[0])
print('Cols %d' %data.shape[1])


####### 5.5.2 Reshape 1D to 2D array
data = array([11,22,33,44,55])
print(data.shape)
data = data.reshape((data.shape[0], 1))
print(data.shape)
print(data)