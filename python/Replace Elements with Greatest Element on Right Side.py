class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        if arr:
            max_ele = max(arr)
            for i in range(len(arr)-1):
                if arr[i] == max_ele:
                    max_ele = max(arr[i+1:])
                arr[i] = max_ele
            arr[-1] = -1
            return arr
