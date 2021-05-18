arr = [4, 7, 1, 89, 25]

for i in range(1, len(arr)):
    j = i - 1
    key = arr[i]
    while arr[j] > key and j >= 0:
        arr[j+1] = arr[j]
        j -= 1
        
    arr[j+1] = key

    print(arr)
