class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = collections.defaultdict(int)
        count = 0
        for i in time:
            remainder = i % 60
            target = (60-i) % 60
            count += d[target]
            d[remainder] +=1
            
        return count
