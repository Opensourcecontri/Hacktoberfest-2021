# Python program to print a 
# square matrix in Z form
  
arr = [[4, 5, 6, 8], 
        [1, 2, 3, 1], 
        [7, 8, 9, 4], 
        [1, 8, 7, 5]]
  
n = len(arr[0])
                   
i=0
for j in range(0, n-1):
    print(arr[i][j], end =" ") 
          
k = 1
for i in range(0, n):
    for j in range(n, 0, -1):
        if(j==n-k):
            print(arr[i][j], end = " ") 
            break; 
    k+=1
  
# Print last row
i=n-1; 
for j in range(0, n):
    print(arr[i][j], end = " ")
