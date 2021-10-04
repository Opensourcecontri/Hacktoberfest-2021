arr=list(map(int,input().split(" ")))
k=int(input())
mx = 0
while k != 0:
    mx = min(arr)
    val = arr.pop(arr.index(mx))
    k-=1
print(val)