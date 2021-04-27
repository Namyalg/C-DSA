def quicksort(arr, l, h):
    pivot = arr[l]
    idx = part(arr, l, h, pivot)
    quicksort(arr, l, idx-1)
    quicksort(arr, idx, h)


def part(arr, l, h, pivot):
    i = l + 1
    j = h
    while i < j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    arr[i], pivot = pivot, arr[i]
    return i+1

a = [2,5,19,8,12,6]

quicksort(a, 0, 5)
print(a)

