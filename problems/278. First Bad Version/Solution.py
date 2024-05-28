# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return self.binarySearch(1, n)

    def binarySearch(self, start: int, end: int) -> int:
        if start == end: return -1 if isBadVersion == False else start
        pivot = (end - start) // 2
        left, right = -1, -1
        if isBadVersion(start + pivot) == True:
            left = self.binarySearch(start, start + pivot)
        else:
            right = self.binarySearch(start + pivot + 1, end)
        if left != -1: return left
        elif right != -1: return right
        else: return -1