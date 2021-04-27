a = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6]

def part(a, l, r):
    pivot = a[l]
    #this is becasue u are swapping from the pivot index itself, so that 
    #it does not get left out, find the position for the pivot and then move
    #around elements that is ideal
    while l <= r:
        while a[l] < pivot:
            l += 1
        while a[r] > pivot:
            r -= 1
        if l <= r:
            a[l], a[r] = a[r], a[l]
            l += 1
            r -= 1
    #a[r], a[st] = a[st], a[r]
    print(a)
    return l

def quicksort(a, l, r):
    if l >= r:
        return

    idx = part(a, l, r)
    quicksort(a, l, idx-1)
    quicksort(a, idx, r)




#print(part(a, 0, 9))
quicksort(a, 0, 9)
print(a)
