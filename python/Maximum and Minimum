# Python3 code to demonstrate working of
# Maximum and Minimum K elements in Tuple
# Using sorted() + loop
 
# initializing tuple
test_tup = (5, 20, 3, 7, 6, 8)
 
# printing original tuple
print("The original tuple is : " + str(test_tup))
 
# initializing K
K = 2
 
# Maximum and Minimum K elements in Tuple
# Using sorted() + loop
res = []
test_tup = list(sorted(test_tup))
 
for idx, val in enumerate(test_tup):
    if idx < K or idx >= len(test_tup) - K:
        res.append(val)
res = tuple(res)
 
# printing result
print("The extracted values : " + str(res))
