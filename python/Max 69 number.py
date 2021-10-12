# https://leetcode.com/problems/maximum-69-number/

class Solution:
    def maximum69Number (self, num: int) -> int:
        n = [str(x) for x in str(num)]
        for i in range(len(n)):
            if n[i]=='6':
                n[i] = '9'
                break
        return ''.join(n)
