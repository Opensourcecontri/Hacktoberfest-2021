class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        arr = []
        for i in A:
            if i not in arr:
                arr.append(i)
            else:
                return i
            
            
//using dict
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        return collections.Counter(A).most_common(1)[0][0]
