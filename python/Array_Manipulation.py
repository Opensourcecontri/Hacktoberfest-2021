#
# Complete the 'arrayManipulation' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def arrayManipulation(n, queries):
    arr = [0]*(n+1)
    max_value = 0
    total_sum = 0

    for query in queries:
        l = query[0]
        h = query[1]
        val = query[2]
        arr[l-1] = arr[l-1] + val
        arr[h] = arr[h]-val
        
    for value in arr:
        total_sum = total_sum + value
        max_value = max(max_value, total_sum)
        
    return max_value
