#Idea in bubble sort is to push the heaviest element to the end, that is the whole point...
#So after every iteration u go one position behind in the array 

a = list(map(int, input().split()))
t = len(a)
c = 0

for i in range(t-3):
    #Since after every pass u have pushed the elements to the end
    for j in range(t - i - 1):
        if a[j+1] < a[j]:
            c += 1
            a[j+1], a[j] = a[j] , a[j+1]
    print(a)
