#A heap is a DSA representing the ADT Priority Queue, it has a root node, and then branches uot
#like a tree. It is a priority queue in the sense that the nodes that appear later have a higher priority


#b = [None, 1,2,3,4,5,6,7]

array = 

#This is the representation of a heap
a = b[1:]
from math import ceil, log
from collections import defaultdict

r = defaultdict(list)
i = 0
j = 0
h = 1
heap = []
while i < ceil(log(len(a), 2)):
  l = pow(2,i) + j
  #print(a[j:l])
  p = a[j:l]
  heap.append(p)
  j = l
  i += 1
print(heap)

for i in heap[1:]:
  for j in i:
    g = b.index(j)
    r[b[g//2]].append(j)
    #print(b[g//2] , j , " ")
  
  print("")

print(r)
