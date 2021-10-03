class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        i = 0
        res = []
        while i < len(nums):
            freq = nums[i]
            val = nums[i+1]
            for j in range(freq):
                res.append(val)
            i+=2
        return res
      
