class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 1: return 0 if nums[0] == target else -1
        value = self.recurse(nums, 0, len(nums) - 1, target)
        return value

    def recurse(self, nums: List[int], start: int, end: int, target: int) -> int:
        if start == end: return start if nums[start] == target else -1
        pivot = (end - start) // 2
        leftVal = self.recurse(nums, start, start + pivot, target)
        rightVal = self.recurse(nums, start + pivot + 1, end, target)
        if leftVal != -1: return leftVal
        if rightVal != -1: return rightVal
        return -1