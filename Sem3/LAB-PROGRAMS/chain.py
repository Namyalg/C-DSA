
def hashit(s):
    hsh = 0
    g = s
    for l in range(len(g)):
        hsh += ((ord(g[l]) * pow(263, l))) 
    hsh = (hsh % p) % m
    return(hsh)
from collections import defaultdict 
p = 1000000007
x = 263  
buckets = dict() 
there = []
m = int(input())
qu = int(input())
for _ in range(qu):
    s = input().split()
    hsh = hashit(s[1])
    if s[0] == "add":
      
        if hsh not in buckets:
            buckets[hsh] = []
        if s[1] not in buckets[hsh]:
            buckets[hsh].append(s[1]) 
    elif s[0] == "check":
        try:
            if int(s[1]) in buckets:
                o = int(s[1])
                print(" ".join(buckets[o][::-1]))
        except:
            pass
    elif s[0] == "find":
        if hsh in buckets:
            if s[1] in buckets[hsh]:
                print("yes")
            else:
                print("no")
        else:
            print("no")
    else:
        try:
            h = hashit(s[1])
            buckets[h].remove(s[1])
        except:
            pass


