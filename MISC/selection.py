#Implementation of bubble sort in python

#Walk through the array, worst case complexity is O(n^2)


a = [10,4,302,-103,593,940,23,12,4,38920,-39303,3829,28203,-392]

for i in range(len(a)):
      for j in range(i+1 , len(a)):
            if a[j] < a[i]:
                a[j], a[i] = a[i], a[j]

print(a)
