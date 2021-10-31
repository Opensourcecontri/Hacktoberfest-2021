#
# Complete the 'pairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#

def pairs(k, arr):
    counter = 0
    set_arr = set(arr)
    for val in arr:
        if val + k in set_arr:
            counter += 1
    return counter
