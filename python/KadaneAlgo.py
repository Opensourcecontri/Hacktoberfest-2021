def maxsumSubArray(nums):
    maxsum=0
    cursum=0
    for i in range(len(nums)):
        cursum=cursum+nums[i]
        if(cursum>maxsum):
            maxsum=cursum
        elif(cursum<0):
            cursum=0
    if maxsum==0:
        return max(nums)
    return maxsum
print(maxsumSubArray([1,2,3,-2,5]))