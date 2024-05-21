class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in table.keys() and table[complement] != i:
                return [i, table[complement]]
            table[nums[i]] = i
        return []