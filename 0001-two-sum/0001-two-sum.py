class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i in range(len(nums)):
            current_num = nums[i]
            pair = target - current_num
            if pair in dic:
                return dic[pair], i
            dic[current_num] = i
        return []
            