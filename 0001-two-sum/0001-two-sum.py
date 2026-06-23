class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            comp = target - x
            if comp in d :
                return d[comp], i
            d[x] = i
        return {}
        
            