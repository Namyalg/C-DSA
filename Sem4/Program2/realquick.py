def part(a, l, r):

    #get the correct posiion of the pivot element and then 
    #return the index
    pivot = a[l]
    while l <= r:
        while a[l] < pivot:
            l += 1
        while a[r] > pivot:
            r -= 1
        if l <= r:
            a[l], a[r] = a[r], a[l]
            l += 1 
            r -= 1
        print(a)
    return l

def quick(arr, left, right):
    if left >= right:
        return
    index = part(arr, left, right);
    quick(arr, left, index - 1);
    quick(arr, index, right);


a = [-9, 18, 12, -199, 23]
print(a)
quick(a, 0, 4)

print(a)
