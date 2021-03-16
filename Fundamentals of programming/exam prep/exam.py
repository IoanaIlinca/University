a = lambda x: [x+1]
b = a(5) # b = [2]
print (b)
c = lambda x: x + b
d = c([1, 2]) 
a = 1 
b = 3
print (a, b, c(4), d[2]) # 1, 3, 7, 2
print (d)

