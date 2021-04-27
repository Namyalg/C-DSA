import math
a = [1,2,3,4,5,6,7,8,9]

l= int(math.log(len(a),2)+ 1)
for i in range(l):
    print(a[i])
    print(a[i*2 + 1], a[i*2 + 2])