class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        localMaxes = [0] * len(nums)
        previous = 0
        for i in range(0, len(nums)):
            localMaxes[i] = max(previous + nums[i], nums[i])
            previous = localMaxes[i]
        return max(localMaxes)