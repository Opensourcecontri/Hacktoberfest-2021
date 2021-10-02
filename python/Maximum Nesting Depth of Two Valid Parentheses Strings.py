class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        A,B = 0,0
        answer = []
        for s in seq:
            if s == '(':
                if B < A:
                    B += 1
                    answer.append(1)
                else:
                    A += 1
                    answer.append(0)
            else:
                if B < A:
                    A -= 1
                    answer.append(0)
                else:
                    B -= 1
                    answer.append(1)
        return answer
