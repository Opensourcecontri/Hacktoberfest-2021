#
# Complete the 'balancedSums' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def balancedSums(arr):
    sum_arr = sum(arr)
    l = len(arr)
    lefty = 0
    for i in range(len(arr)):
        current = arr[i]
        sum_arr -= current
        if lefty == sum_arr:
            return 'YES'
        lefty += current
    return 'NO'
