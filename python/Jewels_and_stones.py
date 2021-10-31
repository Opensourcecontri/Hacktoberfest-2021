test = int(input())
for _ in range(test):
    x,y = input().split()
    print(sum([x.count(i)  for i in y]))
