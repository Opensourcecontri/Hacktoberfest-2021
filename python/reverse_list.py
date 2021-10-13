n= int(input("Number of Elements in the list:"))
lst = []
print("Enter the value of elements:")
for i in range(n):
    a = int(input())
    lst.append(a)
print([i for i in reversed(lst)])
