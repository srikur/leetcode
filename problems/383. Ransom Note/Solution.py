class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        table = {}
        for char in magazine:
            if char not in table: table[char] = 1
            else: table[char] += 1
        for char in ransomNote:
            if (char not in table) or (table[char] == 0): return False
            table[char] -= 1
        return True