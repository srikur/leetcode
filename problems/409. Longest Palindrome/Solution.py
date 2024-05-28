class Solution:
    def longestPalindrome(self, s: str) -> int:
        table = {}
        for char in s:
            if char not in table: table[char] = 1
            else: table[char] += 1
        longest = 0
        hasOdd = False
        for value in table.values():
            if value % 2 == 0: longest += value
            else:
                longest += value - 1
                hasOdd = True
        return longest + (1 if hasOdd else 0)